#include <iostream>
#include <numeric>
#include <chrono>
#include <fstream>
#include <sstream>
#include <cstdlib>
#include "json.hpp"
#include "TemperatureSensor.hpp"
#include "Logger.hpp"
#include "Utilities.hpp"

using namespace std;
using json = nlohmann::json;

TemperatureSensor::TemperatureSensor() {
	ifstream jsonfile("measurements.json");
	if (!jsonfile.is_open()) return;
	json j;
	try {
		jsonfile >> j;
		if (j.empty()) {
			LogEvent("INFO", "No measurements collected yet");
			return;
		}

		for (const auto& m : j) {
			measurement.push_back({ m["timestamp"], m["value"] });
		}
	}
	catch (...) {
		cerr << "[ERROR] Failed to parse measurements.json" << endl;
	}
	jsonfile.close();
	// lettura da file txt
	/*
	string line;
	while (getline(logfile, line)) {
		istringstream ss(line);
		string timestampStr, valueStr;

		if (getline(ss, timestampStr, ',') && getline(ss, valueStr)) {
			try {
				time_t timestamp = stol(timestampStr);
				double value = stod(valueStr);

				measurement.push_back({ timestamp, value });
			}
			catch (...) {
				cout << "Some lines taken from the log.txt file are not formatted correctly" << endl;
			}
		}
	}
	logfile.close();
	*/
}

void TemperatureSensor::addReading(double value) {
	if (measurement.size() >= (double)maxNumberOfValues) {
		measurement.erase(measurement.begin());
	}
	string readableTimestamp = convertToReadableTimestamp(time(nullptr));
	measurement.push_back({readableTimestamp, value});
	ofstream jsonfile("measurements.json");
	json j;
	for (const auto& m : measurement) {
		j.push_back({ {"timestamp", m.timestamp}, {"value", m.value}});
	}
	jsonfile << j.dump(4);
	jsonfile.close();

	LogEvent("INFO", "New measurement has been added");

	notifyObservers(value);
}

double TemperatureSensor::getAverageTemperature() {
	if (measurement.empty()) {
		throw runtime_error("No temperature still collected");
	}
	double sum = accumulate(measurement.begin(), 
		measurement.end(), 
		0.0, 
[](double acc, const Measurement& m) {return acc+ m.value;});
	return sum / measurement.size();
}

double TemperatureSensor::getAverageTemperatureOver(time_t timespan) {
	time_t now = time(nullptr);
	vector<double> recentValues;
	for (const auto &m : measurement) {
		if (now - convertToTimestamp(m.timestamp) >= timespan)
		{
			recentValues.push_back(m.value);
		}
	}

	if (!recentValues.empty()) {
		double sum = 0;
		sum = accumulate(recentValues.begin(), recentValues.end(), 0.0);
		return sum / recentValues.size();
	}
	else {
		return -1;
	}
}

Measurement TemperatureSensor::getMin() {
	if (measurement.empty()) {
		throw runtime_error("No temperature still collected");
	}
	Measurement minMeasurement = measurement[0];
	for (const auto& m : measurement) {
		if (m.value < minMeasurement.value) {
			minMeasurement = m;
		}
	}
	return minMeasurement;
	//return *min_element(values.begin(), values.end());
}

Measurement TemperatureSensor::getMax() {
	if (measurement.empty()) {
		throw runtime_error("No temperature still collected");
	}
	Measurement maxMeasurement = measurement[0];
	for (const auto& m : measurement)
	{
		if (m.value > maxMeasurement.value) {
			maxMeasurement = m;
		}
	}
	return maxMeasurement;
	//return *max_element(measurement.begin(), measurement.end());
}

void TemperatureSensor::attach(IObserver* observer) {
	observers.push_back(observer);
}

void TemperatureSensor::notifyObservers(double newTemperature) {
	for (auto* obs : observers) {
		if (obs) {
			obs->update(newTemperature);
		}
	}
}



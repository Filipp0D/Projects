#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP
#include <vector>
#include <utility>
#include <ctime>
#include <memory>
#include "Measurement.hpp"
#include "IObserver.hpp"
#include "../../../ActuatorControl/ActuatorControl/ActuatorControl/IObserver.hpp"
using namespace std;

class TemperatureSensor {
public:
	TemperatureSensor();
	void addReading(double value);
	double getAverageTemperature();
	double getAverageTemperatureOver(time_t timespan);
	Measurement getMin();
	Measurement getMax();
	void attach(IObserver* observer);
	void removeObserver(IObserver* observer);
	void notifyObservers(double newTemperature);
	

private:
	vector<Measurement> measurement;
	const int maxNumberOfValues = 10;
	vector<IObserver*> observers;

};

#endif TEMPERATURE_SENSOR_HPP

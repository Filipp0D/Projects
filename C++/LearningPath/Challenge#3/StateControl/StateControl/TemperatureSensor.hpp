#ifndef TEMPERATURE_SENSOR_HPP
#define TEMPERATURE_SENSOR_HPP
#include <vector>
#include <utility>
#include <ctime>
#include <memory>
#include <atomic>
#include <thread>
#include "Measurement.hpp"
#include "IObserver.hpp"
using namespace std;

class TemperatureSensor {
public:
	TemperatureSensor();
	~TemperatureSensor();
	void addReading(double value);
	double getAverageTemperature();
	double getAverageTemperatureOver(time_t timespan);
	Measurement getMin();
	Measurement getMax();
	void attach(shared_ptr<IObserver> observer);
	void removeObserver(shared_ptr<IObserver> observer);
	void notifyObservers(double newTemperature);
	void startAsyncSampling(int intervalSeconds = 3);
	void stopAsyncSampling();

private:
	vector<Measurement> measurement;
	const int maxNumberOfValues = 10;
	vector<shared_ptr<IObserver>> observers;
	atomic<bool> isThreadRunning = false;
	thread samplingThread;
	void samplingLoop(int intervalSeconds);
};

#endif TEMPERATURE_SENSOR_HPP

#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP
#include <iostream>
#include "TemperatureSensor.hpp"

using namespace std;

class Actuator {
private:
	string id;
	double threshold;
	bool isActive;
	TemperatureSensor* temperatureSensor = nullptr;
public:
	Actuator(string id, double threshold);
	void check();
	bool getState();
	void setState(bool state);
	string getId();
	void attachTempSensor(TemperatureSensor* s);

};

#endif // !ACTUATOR_HPP

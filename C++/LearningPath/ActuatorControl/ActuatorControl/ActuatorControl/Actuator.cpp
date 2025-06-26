#include <iostream>
#include "Actuator.hpp"
#include "IObserver.hpp"

using namespace std;

Actuator::Actuator(string Id, double Threshold) : id(Id), threshold(Threshold), isActive(false) {};

void Actuator::setState(bool state){
	isActive = state;
}

string Actuator::getId() const {
	return id;
}

bool Actuator::getState() const {
	return isActive;
}

void Actuator::check() {
	if (!temperatureSensor)
	{
		cerr << "No temperature sensor has been attached to the actuator\n";
		return;
	}
	if (temperatureSensor->getAverageTemperature() > threshold && isActive)
	{
		isActive = false;
		cout << "Actuator " << id << "is turned ON\n";
	}
	else if(temperatureSensor->getAverageTemperature() <= threshold && !isActive)
	{
		isActive = true;
		cout << "Actuator " << id << "is turned OFF\n";
	}
}

void Actuator::attachTempSensor(TemperatureSensor* s) {
	temperatureSensor = s;
	cout << "Temperature sensor attached to the actuator " << id << endl;
}

void Actuator::update(double newTemperature) {
	if (newTemperature < threshold && isActive) {
		isActive = false;
		cout << "Actuator " << id << " turned off (temperature over threshold)" << endl;
	}
	else if (newTemperature <= threshold && !isActive){
		cout << "Actuator " << id << " turned on (temperature under threshold)" << endl;
	}
}

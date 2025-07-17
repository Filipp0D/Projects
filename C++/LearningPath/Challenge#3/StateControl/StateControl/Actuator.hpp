#ifndef ACTUATOR_HPP
#define ACTUATOR_HPP
#include <iostream>
#include "TemperatureSensor.hpp"
#include "IObserver.hpp"

using namespace std;

class Actuator : public IObserver {
private:
	string id;
	double threshold;
	bool isActive;
	TemperatureSensor* temperatureSensor = nullptr;

public:
	Actuator(string id, double threshold);
	void check();
	bool getState() const;
	void setState(bool state);
	string getId() const;
	void attachTempSensor(TemperatureSensor* s);

	void update(double newTemperature) override;

	virtual void activate() = 0;
	virtual void  deactivate() = 0;
	virtual string getType() const = 0;

};

#endif // !ACTUATOR_HPP

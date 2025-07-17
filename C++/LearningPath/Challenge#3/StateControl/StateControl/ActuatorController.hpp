#ifndef ACTUATORCONTROLLER_HPP
#define ACTUATORCONTROLLER_HPP
#include <iostream>
#include <vector>
#include <memory>
#include "Actuator.hpp"

class ActuatorController {
private:
	vector<shared_ptr<Actuator>> actuatorVect;
public:
	void addActuator(shared_ptr<Actuator>);
	void printStatus();
};

#endif 
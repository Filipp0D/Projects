#include <iostream>
#include <memory>
#include "ActuatorController.hpp"

using namespace std;

void ActuatorController::addActuator(shared_ptr<Actuator> actuator) {
	actuatorVect.push_back(actuator);
}

void ActuatorController::printStatus() {
	if (!actuatorVect.empty()) {
		for (auto& act : actuatorVect) {
			cout << act->getId() << "->" << act->getState() << endl;
		}
	}
	else {
		cout << "No actuators collected" << endl;
	}
}
#include <iostream>
#include <memory>
#include "Actuator.hpp"
#include "ActuatorController.hpp"
#include "TemperatureSensor.hpp"
#include "Logger.hpp"

using namespace std;

int main() {
	TemperatureSensor tempSens1, tempSens2;

	tempSens1.addReading(23.6);
	tempSens1.addReading(21.1);
	tempSens1.addReading(25.2);
	tempSens1.addReading(23.9);

	tempSens2.addReading(24.6);
	tempSens2.addReading(28.1);
	tempSens2.addReading(31.2);
	tempSens2.addReading(29.9);

	auto actuator1 = make_shared<Actuator>("Act001", 35);
	auto actuator2 = make_shared<Actuator>("Act002", 45);
	//Actuator actuator1("Act001", 30);
	//Actuator actuator2("Act002", 30);

	actuator1->attachTempSensor(&tempSens1);
	actuator2->attachTempSensor(&tempSens2);

	ActuatorController actCtrl;

	actCtrl.addActuator(actuator1);
	actCtrl.addActuator(actuator2);

	cout << "Stato iniziale actuator" << actuator1->getId() << ": " << (actuator1->getState() ? "ON" : "OFF") << endl;
	cout << "Stato iniziale actuator" << actuator2->getId() << ": " << (actuator2->getState() ? "ON" : "OFF") << endl;

	// Controllo dello stato in base alla temperatura media
	actuator1->check();
	actuator2->check();

	// Stato finale
	cout << "Stato dopo check() dell'actuator" << actuator1->getId() << ": " << (actuator1->getState() ? "ON" : "OFF") << endl;
	cout << "Stato dopo check() dell'actuator" << actuator2->getId() << ": " << (actuator2->getState() ? "ON" : "OFF") << endl;

	cout << "Stato degli attuatori:\n";
	actCtrl.printStatus();

	tempSens1.attach(actuator1);
	tempSens2.attach(actuator2);

	tempSens1.addReading(35);
	tempSens2.addReading(33.2);

	tempSens1.startAsyncSampling();
	this_thread::sleep_for(chrono::seconds(15));
	tempSens1.stopAsyncSampling();

	return 0;
}

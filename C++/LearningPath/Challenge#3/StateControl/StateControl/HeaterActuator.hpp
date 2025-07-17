#pragma once
#include "Actuator.hpp"
#include "IStateObserver.hpp"
#include <iostream>

class HeaterActuator : public Actuator, IStateObserver {
	public:
		void activate() override {
			cout << "[Heater] is active\n";
		}
		void deactivate() override {
			cout << "[Heater] is inactive\n";
		}
		string getType() const override {
			cout << "Heater\n";
			return "Heater";
		}
		void onStateChanged(TemperatureState newState) override {
			if (newState == TemperatureState::LOW) {
				activate();
			}
			else {
				deactivate();
			}
		}
};
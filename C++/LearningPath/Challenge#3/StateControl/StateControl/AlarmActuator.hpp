#pragma once
#include "Actuator.hpp"
#include "IStateObserver.hpp"
#include "iostream"

class AlarmActuator : public Actuator, IStateObserver {
	public:
		void activate() override {
			cout << "[Alarm] is active\n";
		}
		void deactivate() override {
			cout << "[Alarm] is inactive";
		}
		string getType() const override {
			cout << "Alarm\n";
			return "Alarm";
		}
		void onStateChanged(TemperatureState newState) override {
			if (newState == TemperatureState::HIGH || newState == TemperatureState::HIGH)
			{
				activate();
			}
			else {
				deactivate();
			}
		}
};
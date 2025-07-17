#pragma once
#include <iostream>
#include "IStateObserver.hpp"
#include "Actuator.hpp"

class FanActuator : public Actuator, IStateObserver{
	public:
		void activate() override {
			cout << "[Fan] is activate (cooling started)\n";
		}
		void deactivate() override {
			cout << "[Fan] is inactive (colling stopped)\n";
		}
		string getType() const override {
			cout << "Fan\n";
			return "Fan";
		}
		void onStateChanged(TemperatureState newState) override{
			if (newState == TemperatureState::HIGH) {
				activate();
			}
			else {
				deactivate();
			}
		}
};

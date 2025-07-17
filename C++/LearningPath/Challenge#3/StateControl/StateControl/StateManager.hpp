#pragma once
#include "Actuator.hpp"
#include "TemperatureState.hpp"
#include "IStateObserver.hpp"
#include <vector>
#include <memory>

class StateManager : public IStateObserver{
	private:
		vector<shared_ptr<Actuator>> actuators;
		vector<shared_ptr<IStateObserver>> observers;
		TemperatureState currentState;
		const double lowerLimit = 15;
		const double upperLimit = 35;
		void setState(TemperatureState newState);
		void applyStateActions();
		void notifyObservers();
	public:
		void addActuator(shared_ptr<Actuator> actuator);
		void addObserver(shared_ptr<IStateObserver> observer);
		void update(double temperature);
		TemperatureState getState() const;
};

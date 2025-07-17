#include "StateManager.hpp"

void StateManager::addActuator(shared_ptr<Actuator> actuator) {
	actuators.push_back(actuator);
}

void StateManager::update(double temperature) {
	TemperatureState newState;
	if (temperature <= lowerLimit) {
		newState = TemperatureState::LOW;

	}
	else if (temperature >= upperLimit) {
		newState = TemperatureState::HIGH;

	}
	else {
		newState = TemperatureState::NORMAL;
	}

	if (currentState != newState) {
		setState(newState);
		applyStateActions();
	}
}

TemperatureState StateManager::getState() const {
	return currentState;
}

void StateManager::setState(TemperatureState newState) {
	if (newState != currentState) {
		currentState = newState;
		cout << "[StateManager] State change to: " << getState() << endl;
		notifyObservers();
	}
}

void StateManager::addObserver(shared_ptr<IStateObserver> observer) {
	observers.push_back(observer);
}

void StateManager::notifyObservers(){
	for (auto& obs : observers) {
		obs->onStateChanged(currentState);
	}

// centralizzato

/*void StateManager::applyStateActions() {
	for (auto& act : actuators)
	{
		string type = act->getType();
		switch (currentState){
		case TemperatureState::LOW:
			act->setState(type == "Heater");
			break;
		case TemperatureState::NORMAL:
			act->setState(false);
			break;
		case TemperatureState::HIGH:
			act->setState(type == "Fan" || type == "Alarm");
			break;
		default:
			break;
		}
	}
*/
}
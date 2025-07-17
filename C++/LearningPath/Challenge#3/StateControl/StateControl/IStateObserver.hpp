#pragma once
#include "TemperatureState.hpp"

class IStateObserver {
public:
	virtual void onStateChanged(TemperatureState newState);
	virtual ~IStateObserver() = default;
};

#pragma once
#include "Event.hpp"

class IEventListener {
	virtual void onEvent(const Event& event) = 0;
	virtual ~IEventListener() = default;
};

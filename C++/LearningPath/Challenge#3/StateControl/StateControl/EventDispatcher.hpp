#pragma once
#include "Event.hpp"
#include "IEventListener.hpp"


class EventDispatcher {
	public:
		void addListener(EventType, IEventListener*);
};

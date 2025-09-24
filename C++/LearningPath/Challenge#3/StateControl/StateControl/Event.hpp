#pragma once
#include <string>
using namespace std;

enum class EventType{
	TEMPERATURE_CHANGED,
	STATE_CHANGED,
	THRESHOLD_EXCEEDED
};

struct Event {
	EventType event;
	string receiverId;
	string payload;			// trying to include library <any> instead of string
};
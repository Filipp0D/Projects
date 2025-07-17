#pragma once
#include <string>
#include <any>
using namespace std;

enum class EventType{
	TEMPERATURE_CHANGED,
	STATE_CHANGED,
	THRESHOLD_EXCEEDED
};

struct Event {
	EventType event;
	string source;
	any payload;
};
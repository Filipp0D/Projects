#pragma once
#include <queue>
#include <mutex>
#include <condition_variable>
#include "Event.hpp"

class EventQueue {
	public:
		void push(const Event& event);
		Event pop();
	private:
		queue<Event> queue;
		mutex mtx;
		condition_variable cv;
};
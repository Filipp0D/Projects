#include "Event.hpp"
#include "EventQueue.hpp"
#include "EventDispatcher.hpp"

void EventDispatcher::start() {
	running = true;
	dispatcherThread = thread(&EventDispatcher::dispatchLoop, this);
}

void EventDispatcher::dispatchLoop() {
	while (running) {
		Event event = eventQueue.pop();

		if (!running) break;

		auto it = handlers.find(event.receiverId);
		if (it != handlers.end()) {
			it->second(event);
		}
	}
}

void EventDispatcher::registerHandler(const string& id, function<void(const Event&)> handler) {
	handlers[id] = handler;
}

void EventDispatcher::stop() {
	running = false;

	eventQueue.push(Event("dispatcher", "stop"));

	if (dispatcherThread.joinable()) {
		dispatcherThread.join();
	}

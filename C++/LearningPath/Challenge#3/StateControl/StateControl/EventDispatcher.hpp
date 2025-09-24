#pragma once
#include <thread>
#include <atomic>
#include <functional>
#include <unordered_map>
#include <string>
#include "Event.hpp"
#include "EventQueue.hpp"
#include "IEventListener.hpp"


class EventDispatcher {
	public:
		EventDispatcher(EventQueue& event);
		~EventDispatcher();

		void start();
		void stop();

		void registerHandler(const string& id, function<void(const Event&)> handler);
	private:
		EventQueue& eventQueue;
		atomic<bool> running;
		thread dispatcherThread;

		unordered_map <string, function<void(const Event&)>> handlers;

		void dispatchLoop();
};

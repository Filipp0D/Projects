#include "EventQueue.hpp"

using namespace std;

void EventQueue::push(const Event& event) {
	unique_lock<mutex> lock(mtx);		// not necessary an unlock, like smart ptrs
	queue.push(event);
	cv.notify_one();
}

Event EventQueue::pop() {
	unique_lock<mutex> lock(mtx);
	cv.wait(lock, [this]() { return !queue.empty(); });		// -> 'Wait until the queue is empty. As soon as it contains something, proceed'
	Event event = queue.front();
	queue.pop();

	return event;
}
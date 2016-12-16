#include "../include/threaded_system.hpp"
#include "../include/message.hpp"

void ThreadedSystem::receive(const Message& message) {
	msg_queue.push(message);
}

Message ThreadedSystem::read() { 
	auto tmp = msg_queue.back(); 
	msg_queue.pop();
	return tmp;
}

bool ThreadedSystem::messages() const {
	 return !msg_queue.empty(); 
}

void ThreadedSystem::start() {
	_thread = std::thread([this](){this->run();});
}

void ThreadedSystem::join() {
	_thread.join();
}

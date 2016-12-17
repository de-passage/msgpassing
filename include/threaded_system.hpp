#ifndef __GUARD_THREADED_SYSTEM_HPP__
#define __GUARD_THREADED_SYSTEM_HPP__

#include "hookable.hpp"
#include <thread>
#include <queue>

template<class Message, class MessageBus>
class ThreadedSystem : public Hookable<Message, MessageBus>
{
	public:
		void receive(const Message& msg);
		virtual void run() = 0;
		void start();
		void join();
		bool messages() const;
		Message read();

	private:
		std::queue<Message> msg_queue;
		std::thread _thread;

};

template<class Message, class MessageBus>
void ThreadedSystem<Message, MessageBus>::receive(const Message& message) {
	msg_queue.push(message);
}

template<class Message, class MessageBus>
Message ThreadedSystem<Message, MessageBus>::read() { 
	auto tmp = msg_queue.back(); 
	msg_queue.pop();
	return tmp;
}

template<class Message, class MessageBus>
bool ThreadedSystem<Message, MessageBus>::messages() const {
	 return !msg_queue.empty(); 
}

template<class Message, class MessageBus>
void ThreadedSystem<Message, MessageBus>::start() {
	_thread = std::thread([this](){this->run();});
}

template<class Message, class MessageBus>
void ThreadedSystem<Message, MessageBus>::join() {
	_thread.join();
}

#endif

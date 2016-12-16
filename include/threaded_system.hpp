#ifndef __GUARD_THREADED_SYSTEM_HPP__
#define __GUARD_THREADED_SYSTEM_HPP__

#include "hookable.hpp"
#include <thread>
#include <queue>

class ThreadedSystem : public Hookable
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


#endif

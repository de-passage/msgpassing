#ifndef __GUARD_MESSAGE_BUS_HPP__
#define __GUARD_MESSAGE_BUS_HPP__

#include <vector>
#include "message.hpp"

class Hookable;

class MessageBus
{
	public: 
		int hook(Hookable* h);

		void broadcast(const Message& msg);
		void send(const Message& msg, int addr);

	private:
		std::vector<Hookable*> _hooks;
};

#endif

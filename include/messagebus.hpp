#ifndef __GUARD_MESSAGE_BUS_HPP__
#define __GUARD_MESSAGE_BUS_HPP__

#include <vector>
#include "message.hpp"

class Hookable;

class MessageBus
{
	public: 
		typedef unsigned int AddressType;

		AddressType hook(Hookable& h);

		void broadcast(const Message& msg);
		void send(const Message& msg, AddressType addr);

	private:
		std::vector<Hookable*> _hooks;
};

#endif

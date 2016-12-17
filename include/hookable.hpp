#ifndef __GUARD_HOOKABLE_HPP__
#define __GUARD_HOOKABLE_HPP__

#include "message.hpp"

class MessageBus;

class Hookable {
	public:
		typedef unsigned int AddressType;
		Hookable();
		MessageBus* set_message_bus(MessageBus* mb);
		
		void send(const Message& msg, AddressType address);
		void broadcast(const Message& msg);

		virtual void receive(const Message&) = 0; 

	private: 
		MessageBus* _msgbus;
};

#endif

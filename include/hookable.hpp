#ifndef __GUARD_HOOKABLE_HPP__
#define __GUARD_HOOKABLE_HPP__

template<class Message, class MessageBus>
class Hookable {
	public:
		typedef Message MessageType;
		typedef MessageBus BusType;
		typedef unsigned int AddressType;
		Hookable();
		BusType* set_message_bus(BusType* mb);
		
		void send(const MessageType& msg, AddressType address);
		void broadcast(const MessageType& msg);

		virtual void receive(const MessageType&) = 0; 

	private: 
		BusType* _msgbus;
};

#include "messagebus.hpp"
#include <algorithm>

template<class Message, class MessageBus>
Hookable<Message, MessageBus>::Hookable() : _msgbus(nullptr) {
}

template<class Message, class MessageBus>
MessageBus* Hookable<Message, MessageBus>::set_message_bus(MessageBus* mb) {
	std::swap(_msgbus, mb);
	return mb;
}

template<class Message, class MessageBus>
void Hookable<Message, MessageBus>::send(const Message& msg, AddressType address) {
	_msgbus->send(msg, address);
}

template<class Message, class MessageBus>
void Hookable<Message, MessageBus>::broadcast(const Message& msg) {
	_msgbus->broadcast(msg);
}

#endif

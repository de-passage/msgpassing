#include "../include/hookable.hpp"

#include "../include/messagebus.hpp"
#include <algorithm>

Hookable::Hookable() : _msgbus(nullptr) {}

MessageBus* Hookable::set_message_bus(MessageBus* mb)
{
	std::swap(_msgbus, mb);
	return mb;
}

void Hookable::send(const Message& msg, int address)
{
	if(address == -1)
		_msgbus->broadcast(msg);
	else
		_msgbus->send(msg, address);
}

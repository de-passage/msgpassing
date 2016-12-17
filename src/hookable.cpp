#include "../include/hookable.hpp"

#include "../include/messagebus.hpp"
#include <algorithm>

Hookable::Hookable() : _msgbus(nullptr) {
}

MessageBus* Hookable::set_message_bus(MessageBus* mb) {
	std::swap(_msgbus, mb);
	return mb;
}

void Hookable::send(const Message& msg, AddressType address) {
	_msgbus->send(msg, address);
}

void Hookable::broadcast(const Message& msg) {
	_msgbus->broadcast(msg);
}

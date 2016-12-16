#include "../include/messagebus.hpp"

#include "../include/hookable.hpp"

#include <algorithm>

int MessageBus::hook(Hookable* h) {
	h->set_message_bus(this);
	_hooks.push_back(h);
	return _hooks.size() - 1;
}

void MessageBus::broadcast(const Message& msg) {
	std::for_each(_hooks.begin(), _hooks.end(), [&msg](auto i) { if(i) i->receive(msg); });
}

void MessageBus::send(const Message& msg, int addr) {
	_hooks.at(addr)->receive(msg);
}

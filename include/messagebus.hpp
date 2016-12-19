#ifndef __GUARD_MESSAGE_BUS_HPP__
#define __GUARD_MESSAGE_BUS_HPP__

#include <vector>
//#include <messaging_policies.hpp>

template<class Message, class MB>
class Hookable;

template<class Message, class AddressingPolicy> 
class BasicMessageBus
{
	public: 
		typedef typename AddressingPolicy::AddressType AddressType;
		typedef BasicMessageBus<Message, AddressingPolicy> Type;
		typedef Hookable<Message, Type> HookType;

		unsigned int hook(HookType& h);
		bool hook(HookType&, AddressType, bool (*)() = [](){return false;});

		void broadcast(const Message& msg);
		void send(const Message& msg, AddressType addr);

	private:
		std::vector<HookType*> _hooks;
		AddressingPolicy policy;
		
		unsigned int next_address() const; 
};

#include <algorithm>
template<class Message, class Policy>
unsigned int BasicMessageBus<Message, Policy>::hook(typename BasicMessageBus<Message, Policy>::HookType& h) {
	h.set_message_bus(this);
	_hooks.push_back(&h);
	return _hooks.size() - 1;
}

template<class Message, class Policy>
bool BasicMessageBus<Message, Policy>::hook(typename BasicMessageBus<Message, Policy>::HookType& h, typename BasicMessageBus<Message, Policy>::AddressType a, bool(*func)()) {
	if(policy.link(next_address(), a)) {
		hook(h);
		return true;
	}
	else
		return func();
}

template<class Message, class Policy>
void BasicMessageBus<Message, Policy>::broadcast(const Message& msg) {
	std::for_each(_hooks.begin(), _hooks.end(), [&msg](auto i) { if(i) i->receive(msg); });
}

template<class Message, class Policy>
void BasicMessageBus<Message, Policy>::send(const Message& msg, typename BasicMessageBus<Message, Policy>::AddressType addr) {
	_hooks.at(policy.dereference(addr))->receive(msg);
}

template<class Message, class Policy>
unsigned int BasicMessageBus<Message, Policy>::next_address() const {
	return _hooks.size();
}

#endif

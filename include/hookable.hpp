#ifndef __GUARD_HOOKABLE_HPP__
#define __GUARD_HOOKABLE_HPP__

class MessageBus;
class Message;

class Hookable {
	public:
		Hookable();
		MessageBus* set_message_bus(MessageBus* mb);
		
		void send(const Message& msg, int address = -1);

		virtual void receive(const Message&) = 0; 

	private: 
		MessageBus* _msgbus;
};

#endif

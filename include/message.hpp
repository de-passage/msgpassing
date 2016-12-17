#ifndef __GUARD_MESSAGE_HPP__
#define __GUARD_MESSAGE_HPP__

#include <string>
#include <SFML/Window/Event.hpp>

struct Message {
	enum MessageType {
		Exit,
		Text, 
		Input
	};
	MessageType type;

	union {
		int code; 
		const std::string& text;
		const sf::Event& input;
	};

	Message() = delete;
	Message(const std::string&);
	Message(const sf::Event&);
	constexpr Message(MessageType t, int c) : type(t), code(c) {}


	static const Message ExitSuccess;
	static const Message ExitFailure;
};

bool operator==(const Message& lhv, const Message& rhv);

#endif

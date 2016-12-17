#include "../include/message.hpp"

const Message Message::ExitSuccess = Message(Message::Exit, 0);

const Message Message::ExitFailure = Message(Message::Exit, 1);


constexpr Message::Message(const std::string& str) : type(MessageType::Text), text(str) {
}

Message::Message(const sf::Event& e) : type(Message::Input), input(e) {
}

bool operator==(const Message& lhv, const Message& rhv) {
	if(lhv.type != rhv.type)
		return false;
	switch(lhv.type) {
		case Message::Exit:
			return lhv.code == rhv.code;
		case Message::Text:
			return lhv.text == rhv.text;
		default:
			return false;
	}
}

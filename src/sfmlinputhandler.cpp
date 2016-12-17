#include "../include/sfmlinputhandler.hpp"
#include "../include/system.hpp"

void SFMLInputHandler::run() {
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if(messages()) {
			auto m = read();
			if(m.type == Message::Exit)
				return;
			else 
				broadcast(Message("Input received"));
		}

	}
}

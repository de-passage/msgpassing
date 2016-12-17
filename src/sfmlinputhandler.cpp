#include "../include/sfmlinputhandler.hpp"

void SFMLInputHandler::run() {
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(200));
		if(messages()) {
			auto m = read();
			if(m.type == Message::Exit)
				return;
		}

	}
}

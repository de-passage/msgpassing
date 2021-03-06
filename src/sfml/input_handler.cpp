#include <sfml/input_handler.hpp>
#include <system.hpp>

void SFMLInputHandler::run() {
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		while(messages()) {
			auto m = read();
			if(m.type == Message::Exit)
				return;
			else 
				send(Message("Input received"), System::Logger);
		}

	}
}

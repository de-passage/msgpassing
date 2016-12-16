#include "../include/sfmlinputhandler.hpp"

void SFMLInputHandler::run() {
	while(true) {
		if(messages() && read() == "EXIT_SIGNAL") {
			return;
		}

	}
}

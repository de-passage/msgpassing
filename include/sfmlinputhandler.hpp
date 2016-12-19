#ifndef __GUARD_SFML_INPUT_HANDLER_HPP__
#define __GUARD_SFML_INPUT_HANDLER_HPP__

#include <message_bus_aliases.hpp>

#include <SFML/Window.hpp>

class SFMLInputHandler : public StandardSystem {
	public:
		void run();
};
#endif

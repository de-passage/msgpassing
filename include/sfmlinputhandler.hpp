#ifndef __GUARD_SFML_INPUT_HANDLER_HPP__
#define __GUARD_SFML_INPUT_HANDLER_HPP__

#include "threaded_system.hpp"
#include <SFML/Window.hpp>


class SFMLInputHandler : public ThreadedSystem {
	public:
		void run();
};
#endif

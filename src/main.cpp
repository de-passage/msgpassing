#include <algorithm>
#include <vector>

#include "../include/system_manager.hpp"
#include "../include/logger.hpp"
#include "../include/renderer.hpp"
#include "../include/sfmlinputhandler.hpp"
#include "../include/system.hpp"

#include <iostream>

int main()
{
	SystemManager mb; 
	Logger log(std::cout);
	SFMLRenderer window(sf::VideoMode(800,600), "The architecture works!");
	SFMLInputHandler input;
	mb.hook(log, System::Logger);
	mb.hook(window, System::Renderer);
	mb.hook(input, Syste::InputHandler);
	mb.run();
	return 0;
}

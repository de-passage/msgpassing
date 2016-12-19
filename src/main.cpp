#include <algorithm>
#include <vector>

#include <system_manager.hpp>
#include <logger.hpp>
#include <sfml/renderer.hpp>
#include <sfml/input_handler.hpp>
#include <system.hpp>

#include <iostream>

int main()
{
	SystemManager mb; 
	Logger log(std::cout);
	SFMLRenderer window(sf::VideoMode(800,600), "The architecture works!");
	SFMLInputHandler input;
	mb.hook(log, System::Logger);
	mb.hook(window, System::Renderer);
	mb.hook(input, System::InputHandler);
	mb.run();
	return 0;
}

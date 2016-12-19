#ifndef __GUARD_RENDERER_HPP__
#define __GUARD_RENDERER_HPP__

#include <message_bus_aliases.hpp>

#include <SFML/Graphics/RenderWindow.hpp>

class SFMLRenderer : public StandardSystem, public sf::RenderWindow {
	public: 
		SFMLRenderer(const sf::VideoMode&, const sf::String&, sf::Uint32 = sf::Style::Default);
		void run();
};

#endif


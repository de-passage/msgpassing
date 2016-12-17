#include "../include/renderer.hpp"
#include <SFML/Graphics.hpp>

SFMLRenderer::SFMLRenderer(const sf::VideoMode& vm, const sf::String& n, sf::Uint32 s) : sf::RenderWindow(vm, n, s)
{
	setActive(false);
}

void SFMLRenderer::run() {
	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Green);
	sf::Event event;
	while(true) {
		if(messages()) {
			if(read() == "EXIT_SIGNAL") {
				close();
				return;
			}
		}
		while(isOpen() && pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				broadcast("EXIT_SIGNAL");
		}
		clear();
		draw(shape);
		display();

	}
}

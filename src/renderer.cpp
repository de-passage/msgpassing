#include "../include/renderer.hpp"
#include <SFML/Graphics.hpp>

#include "../include/system.hpp"

SFMLRenderer::SFMLRenderer(const sf::VideoMode& vm, const sf::String& n, sf::Uint32 s) : sf::RenderWindow(vm, n, s)
{
	setActive(false);
}

void SFMLRenderer::run() {
	sf::CircleShape shape(100.f);

	shape.setFillColor(sf::Color::Green);
	sf::Event event;
	while(true) {
		std::this_thread::sleep_for(std::chrono::milliseconds(50));
		while(messages()) {
			if(read().type == Message::Exit) {
				close();
				return;
			}
			else 
				send(Message("Renderer received an invalid message"), System::Logger);
		}
		while(isOpen() && pollEvent(event)) {
			if(event.type == sf::Event::Closed)
				broadcast(Message::ExitSuccess);
			else 
				send(Message(event), System::InputHandler);

		}
		clear();
		draw(shape);
		display();

	}
}

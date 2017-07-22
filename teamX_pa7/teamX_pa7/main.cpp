#include "GameManager.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 800), "Chess");
	GameManager game;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed){
				window.close();
			}
			else {
				game.processEvent(event);
			}
		}

		window.clear();
		game.draw(window);
		window.display();
	}
	return 0;
}
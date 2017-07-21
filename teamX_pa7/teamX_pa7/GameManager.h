#pragma once
#include "Everything.h"

class GameManager{
public:
	void processEvent(sf::Event _event);
	void draw(sf::RenderWindow _window);
	void addObject(GameObject * _obj);

	GameManager();
	GameManager(GameManager & _old);
	~GameManager();
private:
	std::vector<GameObject*> gameObjects;
	Board gameBoard;
};
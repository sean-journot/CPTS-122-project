#pragma once
#include <SFML/Graphics.hpp>
# include "GameObject.h"
#include "Board.h"

class Board;

class GameManager{
public:
	void processEvent(sf::Event _event);
	void draw(sf::RenderWindow & _window);
	void addObject(GameObject * _obj);

	GameManager();
	// should never be copied!
	~GameManager();
private:
	std::vector<GameObject*> gameObjects;
	Board * gameBoard;
};
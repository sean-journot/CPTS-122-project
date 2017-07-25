#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
# include "GameObject.h"
#include "Board.h"

class Board;

class GameManager{
public:
	void processEvent(sf::Event _event);
	void draw(sf::RenderWindow & _window);
	void addObject(GameObject * _obj);
	void switchPlayer();
	void playerNoClick(std::string _player);
	void gameOverBro();
	void reset();

	GameManager();
	// should never be copied!
	~GameManager();
private:
	bool player1Turn;
	std::string player1Name;
	std::string player2Name;
	std::vector<GameObject*> gameObjects;
	Board * gameBoard;
};
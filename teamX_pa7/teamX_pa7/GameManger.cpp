#include "GameManager.h"

GameManager::GameManager()
{
	gameBoard = new Board(this);
}

GameManager::~GameManager(){
	delete gameBoard;
}

void GameManager::processEvent(sf::Event _event){
	if (_event.type == sf::Event::MouseButtonPressed){
		if (_event.mouseButton.button == sf::Mouse::Left){
			for (int i = 0; i < gameObjects.size(); i++){
				if (gameObjects[i] != nullptr && gameObjects[i]->getBox().contains(_event.mouseButton.x, _event.mouseButton.y)){
					gameObjects[i]->onClick();
				}
			}
		}
	}
}

void GameManager::draw(sf::RenderWindow & _window){
	for (int i = gameObjects.size() - 1; i >= 0; i--){
		if (gameObjects[i] != nullptr){
			_window.draw(*gameObjects[i]);
		}
	}
}

void GameManager::addObject(GameObject * _obj){
	gameObjects.push_back(_obj);
}


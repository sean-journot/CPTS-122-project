#include "GameManager.h"

GameManager::GameManager()
{
	gameBoard = new Board(this);
}

GameManager::GameManager(GameManager & _old){

}

GameManager::~GameManager(){

}

void GameManager::processEvent(sf::Event _event){

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


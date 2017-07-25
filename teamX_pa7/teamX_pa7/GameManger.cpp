#include "GameManager.h"

GameManager::GameManager()
{
	gameBoard = new Board(this);
	player1Turn = false;
	player1Name = "bob";
	player2Name = "steve";
	gameBoard->setPlayer1Name(player1Name);
	gameBoard->setPlayer2Name(player2Name);
	gameBoard->player1Click();
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

void GameManager::switchPlayer(){
	gameBoard->boardNoClick();
	gameBoard->boadResetCallBack();
	gameBoard->player1NoClick();
	gameBoard->player2NoClick();
	if (player1Turn){
		player1Turn = false;
		gameBoard->player1Click();
	}
	else{
		player1Turn = true;
		gameBoard->player2Click();
	}
}

void GameManager::playerNoClick(std::string _player){
	if (_player == player1Name){
		gameBoard->player1NoClick();
	}
	if (_player == player2Name){
		gameBoard->player2NoClick();
	}
}

void GameManager::gameOverBro(){
	if (!player1Turn){
		std::cout << "player 1 wins!" << std::endl;
	}
	else{
		std::cout << "player 2 wins!" << std::endl;
	}
	reset();
}

void GameManager::reset(){
	delete gameBoard;
	gameObjects.erase(gameObjects.begin(), gameObjects.end());
	gameBoard = new Board(this);
	player1Turn = false;
	player1Name = "bob";
	player2Name = "steve";
	gameBoard->setPlayer1Name(player1Name);
	gameBoard->setPlayer2Name(player2Name);
	gameBoard->player1Click();
}
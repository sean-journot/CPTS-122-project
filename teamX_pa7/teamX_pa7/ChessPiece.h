#pragma once
#include "GameObject.h"

class BoardSquare;
class GameManager;

class ChessPiece
	:public GameObject
{
public:
	virtual void onClick();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	BoardSquare * getBoardPtr();
	void setBoardPtr(BoardSquare * _bPtr);
	void movePiece(sf::Vector2f _pos);
	sf::FloatRect getBox();
	bool capture();
	bool isKing();
	std::string getPlayerName();
	void setPlayerName(std::string _name);
	virtual std::vector<std::string> getMoves() = 0;

	ChessPiece(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	virtual ~ChessPiece();
protected:
	bool king;
	std::string playerName;
	GameManager & manager;
	sf::Sprite sprite;
	BoardSquare * bPtr;
};

#include "BoardSquare.h"
#include "GameManager.h"
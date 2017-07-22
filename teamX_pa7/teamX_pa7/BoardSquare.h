#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ChessPiece.h"

class GameManager;

class BoardSquare
	:public GameObject
{
public:
	void setCallBack(ChessPiece * _callBack);
	void onClick();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0));
	~BoardSquare();
private:
	sf::Sprite sprite;
	GameManager & manager;
	ChessPiece * callBack;
	friend class Board;
	BoardSquare * uPtr;
	BoardSquare * dPtr;
	BoardSquare * lPtr;
	BoardSquare * rPtr;
	ChessPiece * pPtr;
};

#include "GameManager.h"
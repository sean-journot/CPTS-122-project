#pragma once
#include "GameManager.h"
#include "GameObject.h"

class BoardSquare
	:public GameObject, public sf::Sprite
{
public:
	void setCallBack(ChessPiece * _callBack);
	void onClick();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;

	BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0));
	~BoardSquare();
private:
	GameManager & manager;
	ChessPiece * callBack;
	friend class Board;
	BoardSquare * uPtr;
	BoardSquare * dPtr;
	BoardSquare * lPtr;
	BoardSquare * rPtr;
	ChessPiece * pPtr;
};
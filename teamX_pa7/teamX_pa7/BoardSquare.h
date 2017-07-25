#pragma once
#include <SFML/Graphics.hpp>
#include "GameObject.h"
#include "ChessPiece.h"

class GameManager;

class BoardSquare
	:public GameObject
{
public:
	void setClickable(bool _set);
	void setCallBack(BoardSquare * _callBack);
	void onClick();
	virtual void draw(sf::RenderTarget& target, sf::RenderStates states) const;
	sf::FloatRect getBox();
	sf::Vector2f getPos();
	void setPiecePointer(ChessPiece * pPtr);
	ChessPiece * getPiecePointer();
	BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0));
	~BoardSquare();
private:
	BoardSquare * getMovePtr(std::string _move, BoardSquare * _cPtr);
	sf::Sprite sprite;
	GameManager & manager;
	BoardSquare * callBack;
	friend class Board;
	BoardSquare * uPtr;
	BoardSquare * dPtr;
	BoardSquare * lPtr;
	BoardSquare * rPtr;
	ChessPiece * pPtr;
};

#include "GameManager.h"
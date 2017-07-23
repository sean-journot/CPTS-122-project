#pragma once
#include "ChessPiece.h"

class Knight
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Knight(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~Knight();
private:
	std::vector<std::string> moves;
};
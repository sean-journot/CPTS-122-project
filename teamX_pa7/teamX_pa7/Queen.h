#pragma once
#include "ChessPiece.h"

class Queen
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Queen(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~Queen();
private:
	std::vector<std::string> moves;
};
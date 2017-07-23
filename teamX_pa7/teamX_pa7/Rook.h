#pragma once
#include "ChessPiece.h"

class Rook
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Rook(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~Rook();
private:
	std::vector<std::string> moves;
};
#pragma once
#include "ChessPiece.h"

class Pawn
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Pawn(GameManager & _manager, sf::Texture & _texture, bool swapMoves, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~Pawn();
private:
	std::vector<std::string> moves;
};


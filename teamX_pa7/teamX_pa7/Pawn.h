#pragma once
#include "ChessPiece.h"

class Pawn
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Pawn(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0));
	~Pawn();
private:
	std::vector<std::string> moves;
};


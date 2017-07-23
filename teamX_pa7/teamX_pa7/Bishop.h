#pragma once
#include "ChessPiece.h"

class Bishop
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	Bishop(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~Bishop();
private:
	std::vector<std::string> moves;
};
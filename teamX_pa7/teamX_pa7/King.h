#pragma once
#include "ChessPiece.h"

class King
	:public ChessPiece
{
public:
	std::vector<std::string> getMoves();
	King(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos = sf::Vector2f(0, 0), BoardSquare * _bPtr = nullptr);
	~King();
private:
	std::vector<std::string> moves;
};
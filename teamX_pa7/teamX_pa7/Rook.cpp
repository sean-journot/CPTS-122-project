#include "Rook.h"

std::vector<std::string> Rook::getMoves(){
	return moves;
}

Rook::Rook(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	moves.push_back("TYU");
	moves.push_back("TYD");
	moves.push_back("TYL");
	moves.push_back("TYR");
}

Rook::~Rook(){

}
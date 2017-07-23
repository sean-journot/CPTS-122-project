#include "Queen.h"

std::vector<std::string> Queen::getMoves(){
	return moves;
}

Queen::Queen(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	moves.push_back("TYL");
	moves.push_back("TYR");
	moves.push_back("TYU");
	moves.push_back("TYD");
	moves.push_back("TYDL");
	moves.push_back("TYDR");
	moves.push_back("TYUL");
	moves.push_back("TYUR");
}

Queen::~Queen(){

}
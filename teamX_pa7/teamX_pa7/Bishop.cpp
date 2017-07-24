#include "Bishop.h"

std::vector<std::string> Bishop::getMoves(){
	return moves;
}

Bishop::Bishop(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	king = false;
	moves.push_back("TYUL");
	moves.push_back("TYUR");
	moves.push_back("TYDL");
	moves.push_back("TYDR");
}

Bishop::~Bishop(){

}
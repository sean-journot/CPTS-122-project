#include "King.h"

std::vector<std::string> King::getMoves(){
	return moves;
}

King::King(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	moves.push_back("TNU");
	moves.push_back("TND");
	moves.push_back("TNL");
	moves.push_back("TNR");
	moves.push_back("TNLU");
	moves.push_back("TNLD");
	moves.push_back("TNRU");
	moves.push_back("TNRD");
}

King::~King(){

}
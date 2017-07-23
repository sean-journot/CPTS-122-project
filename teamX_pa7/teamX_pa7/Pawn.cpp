#include "Pawn.h"

std::vector<std::string> Pawn::getMoves(){
	return moves;
}

Pawn::Pawn(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos)
:ChessPiece(_manager, _texture, _pos)
{
	moves.push_back("ENUL");
	moves.push_back("ENUR");
	moves.push_back("BNU");
}

Pawn::~Pawn(){

}
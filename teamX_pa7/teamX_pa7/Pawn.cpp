#include "Pawn.h"

std::vector<std::string> Pawn::getMoves(){
	return moves;
}

Pawn::Pawn(GameManager & _manager, sf::Texture & _texture, bool swapMoves, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	king = false;
	if (!swapMoves){
		moves.push_back("ENUL");
		moves.push_back("ENUR");
		moves.push_back("BNU");
	}
	else{
		moves.push_back("ENDL");
		moves.push_back("ENDR");
		moves.push_back("BND");
	}
}

Pawn::~Pawn(){

}
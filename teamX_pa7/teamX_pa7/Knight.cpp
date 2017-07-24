#include "Knight.h"

std::vector<std::string> Knight::getMoves(){
	return moves;
}

Knight::Knight(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:ChessPiece(_manager, _texture, _pos, _bPtr)
{
	king = false;
	moves.push_back("TNUUL");
	moves.push_back("TNUUR");
	moves.push_back("TNDDL");
	moves.push_back("TNDDR");
	moves.push_back("TNLLU");
	moves.push_back("TNLLD");
	moves.push_back("TNRRU");
	moves.push_back("TNRRD");
}

Knight::~Knight(){

}
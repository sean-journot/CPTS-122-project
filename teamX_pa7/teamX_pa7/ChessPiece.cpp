#include "ChessPiece.h"

void ChessPiece::onClick(){
	// does nothing on click
}

void ChessPiece::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

BoardSquare * ChessPiece::getBoardPtr(){
	return bPtr;
}

void ChessPiece::setBoardPtr(BoardSquare * _bPtr){
	bPtr = _bPtr;
}

void ChessPiece::movePiece(sf::Vector2f _pos){
	sprite.move(_pos);
}

sf::FloatRect ChessPiece::getBox(){
	return sprite.getGlobalBounds();
}

bool ChessPiece::isKing(){
	return king;
}

ChessPiece::ChessPiece(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos, BoardSquare * _bPtr)
:manager(_manager)
{
	sprite.setTexture(_texture);
	sprite.move(_pos);
	bPtr = _bPtr;
	bPtr->setPiecePointer(this);
}

ChessPiece::~ChessPiece(){
	//nothing t do here
}
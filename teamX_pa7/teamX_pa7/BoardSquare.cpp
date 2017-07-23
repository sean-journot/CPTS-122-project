#include "BoardSquare.h"
#include <iostream>

void BoardSquare::setCallBack(ChessPiece * _callBack){
	callBack = _callBack;
}

void BoardSquare::onClick(){
	std::cout << "square clicked: " << this << std::endl;
}

void BoardSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

sf::FloatRect BoardSquare::getBox(){
	return sprite.getGlobalBounds();
}

sf::Vector2f BoardSquare::getPos(){
	return sprite.getPosition();
}

BoardSquare::BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos)
: manager(_manager)
{
	sprite.setTexture(_texture);
	sprite.move(_pos);
	uPtr = nullptr;
	dPtr = nullptr;
	lPtr = nullptr;
	rPtr = nullptr;
	pPtr = nullptr;
}

BoardSquare::~BoardSquare(){
	// nothig to do here
}
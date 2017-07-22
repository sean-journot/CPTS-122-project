#include "BoardSquare.h"

void BoardSquare::setCallBack(ChessPiece * _callBack){
	callBack = _callBack;
}

void BoardSquare::onClick(){

}

void BoardSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	target.draw(sprite, states);
}

BoardSquare::BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos)
: manager(_manager)
{
	sprite.setTexture(_texture);
	sprite.move(_pos);
}

BoardSquare::~BoardSquare(){
	// nothig to do here
}
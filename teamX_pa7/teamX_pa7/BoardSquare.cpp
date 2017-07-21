#include "BoardSquare.h"

void BoardSquare::setCallBack(ChessPiece * _callBack){

}

void BoardSquare::onClick(){

}

void BoardSquare::draw(sf::RenderTarget& target, sf::RenderStates states) const{
	Sprite::draw(target, states);
}

BoardSquare::BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos)
: manager(_manager), Sprite(_texture)
{
	move(_pos);
}

BoardSquare::~BoardSquare(){

}
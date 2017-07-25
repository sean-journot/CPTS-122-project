#include "BoardSquare.h"
#include <iostream>

void BoardSquare::setClickable(bool _set)
{
	GameObject::setClickable(_set);
	if (isClickable()){
		sprite.setColor(sf::Color(0,255,0,200));
	}
	else{
		sprite.setColor(sf::Color(255, 255, 255, 255));
	}
}

void BoardSquare::setCallBack(BoardSquare * _callBack){
	callBack = _callBack;
}

ChessPiece * BoardSquare::getPiecePointer(){
	return pPtr;
}

void BoardSquare::onClick(){
	bool moveMade = false;
	int moveSquareCondition;
	bool repeatable;
	std::vector<std::string> moves;
	std::string mov;
	BoardSquare * cPtr = this;
	if (isClickable()){
		if (callBack != nullptr){
			if (pPtr != nullptr){
				if (pPtr->capture()){
					return;
				}
			}
			callBack->getPiecePointer()->movePiece(sprite.getPosition());
			pPtr = callBack->getPiecePointer();
			pPtr->setBoardPtr(this);
			callBack->setPiecePointer(nullptr);
			callBack->setClickable(false);
			callBack = nullptr;
			manager.switchPlayer();
		}
		else{
			moves = pPtr->getMoves();
			for (int i = moves.size() - 1; i >= 0; i--){
				mov = moves[i];
				cPtr = this;
				switch (mov[0]){
				case 'E':
					moveSquareCondition = 1;
					break;
				case 'B':
					moveSquareCondition = 2;
					break;
				case 'T':
					moveSquareCondition = 3;
					break;
				}
				if (mov[1] == 'Y'){
					repeatable = true;
				}
				else{
					repeatable = false;
				}
				mov = mov.substr(2, mov.length());
				cPtr = getMovePtr(mov, this);
				if (repeatable){
					switch (moveSquareCondition){
					case 1:
						std::cout << "ERROR: ILLOGICAL MOVE" << mov << std::endl;
						break;
					case 2:
						while (cPtr != nullptr && cPtr->pPtr == nullptr){
							cPtr->setClickable(true);
							cPtr->setCallBack(this);
							setClickable(false);
							moveMade = true;
							cPtr = getMovePtr(mov, cPtr);
						}
						break;
					case 3:
						while (cPtr != nullptr && cPtr->pPtr == nullptr){
							cPtr->setClickable(true);
							cPtr->setCallBack(this);
							setClickable(false);
							moveMade = true;
							cPtr = getMovePtr(mov, cPtr);
						}
						if (cPtr != nullptr && cPtr->pPtr->getPlayerName() != pPtr->getPlayerName()){
							cPtr->setClickable(true);
							cPtr->setCallBack(this);
							setClickable(false);
							moveMade = true;
						}
					}
				}
				else{
					switch (moveSquareCondition){
					case 1:
						if (cPtr != nullptr && cPtr->pPtr != nullptr && cPtr->pPtr->getPlayerName() != pPtr->getPlayerName()){
							cPtr->setClickable(true);
							cPtr->setCallBack(this);
							setClickable(false);
							moveMade = true;
						}
						break;
					case 2:
						if (cPtr != nullptr && cPtr->pPtr == nullptr){
							cPtr->setClickable(true);
							cPtr->setCallBack(this);
							setClickable(false);
							moveMade = true;
						}
						break;
					case 3:
						if (cPtr != nullptr){
							if (cPtr->pPtr != nullptr){
								if (cPtr->pPtr->getPlayerName() != pPtr->getPlayerName()){
									cPtr->setClickable(true);
									cPtr->setCallBack(this);
									setClickable(false);
									moveMade = true;
								}
							}
							else{
								cPtr->setClickable(true);
								cPtr->setCallBack(this);
								setClickable(false);
								moveMade = true;
							}
						}
					}
				}
			}
			if (moveMade){
				manager.playerNoClick(pPtr->getPlayerName());
			}
		}
	}
}

BoardSquare * BoardSquare::getMovePtr(std::string _move, BoardSquare * _cPtr){
	for (int i = 0; i < _move.length() && _cPtr != nullptr; i++){
		switch (_move[i]){
		case 'U':
			_cPtr = _cPtr->uPtr;
			break;
		case 'D':
			_cPtr = _cPtr->dPtr;
			break;
		case 'L':
			_cPtr = _cPtr->lPtr;
			break;
		case 'R':
			_cPtr = _cPtr->rPtr;
		}
	}
	return _cPtr;
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

void BoardSquare::setPiecePointer(ChessPiece * _pPtr){
	pPtr = _pPtr;
}

BoardSquare::BoardSquare(GameManager & _manager, sf::Texture & _texture, sf::Vector2f _pos)
: manager(_manager)
{
	callBack = nullptr;
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
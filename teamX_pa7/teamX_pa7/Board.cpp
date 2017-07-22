#include "Board.h"

Board::Board(GameManager * _manager)
: manager(_manager)
{
	redSqr.loadFromFile("redSquare.bmp");
	blackSqr.loadFromFile("blackSquare.bmp");
	redPawn.loadFromFile("redPawn.bmp");
	redRook.loadFromFile("redRook.bmp");
	redKnight.loadFromFile("redKnight.bmp");
	redBishop.loadFromFile("redBishop.bmp");
	redQueen.loadFromFile("redQueen.bmp");
	redKing.loadFromFile("redKing.bmp");
	blackPawn.loadFromFile("blackPawn.bmp");
	blackRook.loadFromFile("blackRook.bmp");
	blackKnight.loadFromFile("blackKnight.bmp");
	blackBishop.loadFromFile("blackBishop.bmp");
	blackQueen.loadFromFile("blackQueen.bmp");
	blackKing.loadFromFile("blackKing.bmp");
	populateSqr();
	populatePieces();
	populateBdr();
	for (int i = 0; i < 16; i++){
		manager->addObject(player1Pieces[i]);
	}
	for (int i = 0; i < 16; i++){
		manager->addObject(player2Pieces[i]);
	}
	for (int i = 0; i < 64; i++){
		manager->addObject(boardSqr[i]);
	}
	for (int i = 0; i < 8; i++){
		manager->addObject(boardBdr[i]);
	}
}

Board::~Board(){
	for (int i = 0; i < 16; i++){
		if (player1Pieces[i] != nullptr){
			delete player1Pieces[i];
		}
	}
	for (int i = 0; i < 16; i++){
		if (player2Pieces[i] != nullptr){
			delete player2Pieces[i];
		}
	}
	for (int i = 0; i < 64; i++){
		if (boardSqr[i] != nullptr){
			delete boardSqr[i];
		}
	}
	for (int i = 0; i < 8; i++){
		if (boardBdr[i] != nullptr){
			delete boardBdr[i];
		}
	}
}

void Board::populateSqr(){
	sf::Vector2f pos;
	float scale = 1;
	bool j = false;
	for (int i = 0; i < 64; i++){
		pos.x = (i % 8) * scale;
		pos.y = (i / 8) * scale;
		if (i % 8 == 0){
			j = !j;
		}
		if (i % 2 == 0){
			if (!j){
				boardSqr[i] = new BoardSquare(*manager, redSqr, pos);
			}
			else{
				boardSqr[i] = new BoardSquare(*manager, blackSqr, pos);
			}
		}
		else{
			if (!j){
				boardSqr[i] = new BoardSquare(*manager, blackSqr, pos);
			}
			else{
				boardSqr[i] = new BoardSquare(*manager, redSqr, pos);
			}
		}
	}
}

void Board::populatePieces(){

}

void Board::populateBdr(){

}
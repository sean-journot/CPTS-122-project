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
	for (int i = 0; i < 16; i++){
		manager->addObject(player1Pieces[i]);
	}
	for (int i = 0; i < 16; i++){
		manager->addObject(player2Pieces[i]);
	}
	for (int i = 0; i < 64; i++){
		manager->addObject(boardSqr[i]);
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
}

void Board::populateSqr(){
	sf::Vector2f pos;
	float scale = 100;
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
	for (int i = 0; i < 8; i++){
		for (int j = 0; j < 7; j++){
			boardSqr[8 * i + j]->rPtr = boardSqr[8 * i + j + 1];
			boardSqr[8 * i + j + 1]->lPtr = boardSqr[8 * i + j];
		}
	}
	for (int i = 0; i < 7; i++){
		for (int j = 0; j < 8; j++){
			boardSqr[8 * i + j]->dPtr = boardSqr[8 * (1 + i) + j];
			boardSqr[8 * (1 + i) + j]->uPtr = boardSqr[8 * i + j];
		}
	}
}

void Board::populatePieces(){
	player1Pieces[0] = new Rook(*manager, redRook, boardSqr[56]->getPos(), boardSqr[56]);
	player1Pieces[1] = new Knight(*manager, redRook, boardSqr[57]->getPos(), boardSqr[57]);
	player1Pieces[2] = new Bishop(*manager, redRook, boardSqr[58]->getPos(), boardSqr[58]);
	player1Pieces[3] = new King(*manager, redRook, boardSqr[59]->getPos(), boardSqr[59]);
	player1Pieces[4] = new Queen(*manager, redRook, boardSqr[60]->getPos(), boardSqr[60]);
	player1Pieces[5] = new Bishop(*manager, redRook, boardSqr[61]->getPos(), boardSqr[61]);
	player1Pieces[6] = new Knight(*manager, redRook, boardSqr[62]->getPos(), boardSqr[62]);
	player1Pieces[7] = new Rook(*manager, redRook, boardSqr[63]->getPos(), boardSqr[63]);
}
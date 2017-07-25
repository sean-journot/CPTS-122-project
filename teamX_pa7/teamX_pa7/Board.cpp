#include "Board.h"

Board::Board(GameManager * _manager)
: manager(_manager)
{
	redSqr.loadFromFile("redSquare.bmp");
	blackSqr.loadFromFile("blackSquare.bmp");
	redPawn.loadFromFile("redPawn.png");
	redRook.loadFromFile("redRook.png");
	redKnight.loadFromFile("redKnight.png");
	redBishop.loadFromFile("redBishop.png");
	redQueen.loadFromFile("redQueen.png");
	redKing.loadFromFile("redKing.png");
	blackPawn.loadFromFile("blackPawn.png");
	blackRook.loadFromFile("blackRook.png");
	blackKnight.loadFromFile("blackKnight.png");
	blackBishop.loadFromFile("blackBishop.png");
	blackQueen.loadFromFile("blackQueen.png");
	blackKing.loadFromFile("blackKing.png");
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
	player1Pieces[1] = new Knight(*manager, redKnight, boardSqr[57]->getPos(), boardSqr[57]);
	player1Pieces[2] = new Bishop(*manager, redBishop, boardSqr[58]->getPos(), boardSqr[58]);
	player1Pieces[3] = new King(*manager, redKing, boardSqr[59]->getPos(), boardSqr[59]);
	player1Pieces[4] = new Queen(*manager, redQueen, boardSqr[60]->getPos(), boardSqr[60]);
	player1Pieces[5] = new Bishop(*manager, redBishop, boardSqr[61]->getPos(), boardSqr[61]);
	player1Pieces[6] = new Knight(*manager, redKnight, boardSqr[62]->getPos(), boardSqr[62]);
	player1Pieces[7] = new Rook(*manager, redRook, boardSqr[63]->getPos(), boardSqr[63]);
	for (int i = 0; i < 8; i++){
		player1Pieces[i+8] = new Pawn(*manager, redPawn, false, boardSqr[48+i]->getPos(), boardSqr[48+i]);
	}

	player2Pieces[0] = new Rook(*manager, blackRook, boardSqr[0]->getPos(), boardSqr[0]);
	player2Pieces[1] = new Knight(*manager, blackKnight, boardSqr[1]->getPos(), boardSqr[1]);
	player2Pieces[2] = new Bishop(*manager, blackBishop, boardSqr[2]->getPos(), boardSqr[2]);
	player2Pieces[3] = new Queen(*manager, blackQueen, boardSqr[3]->getPos(), boardSqr[3]);
	player2Pieces[4] = new King(*manager, blackKing, boardSqr[4]->getPos(), boardSqr[4]);
	player2Pieces[5] = new Bishop(*manager, blackBishop, boardSqr[5]->getPos(), boardSqr[5]);
	player2Pieces[6] = new Knight(*manager, blackKnight, boardSqr[6]->getPos(), boardSqr[6]);
	player2Pieces[7] = new Rook(*manager, blackRook, boardSqr[7]->getPos(), boardSqr[7]);
	for (int i = 0; i < 8; i++){
		player2Pieces[i + 8] = new Pawn(*manager, blackPawn, true, boardSqr[8 + i]->getPos(), boardSqr[8 + i]);
	}
}

void Board::setPlayer1Name(std::string _name){
	for (int i = 0; i < 16; i++){
		player1Pieces[i]->setPlayerName(_name);
	}
}

void Board::setPlayer2Name(std::string _name){
	for (int i = 0; i < 16; i++){
		player2Pieces[i]->setPlayerName(_name);
	}
}

void Board::player1Click(){
	for (int i = 0; i < 16; i++){
		if (player1Pieces[i]->getBoardPtr() != nullptr){
			player1Pieces[i]->getBoardPtr()->setClickable(true);
		}
	}
}

void Board::player1NoClick(){
	for (int i = 0; i < 16; i++){
		if (player1Pieces[i]->getBoardPtr() != nullptr){
			player1Pieces[i]->getBoardPtr()->setClickable(false);
		}
	}
}

void Board::player2Click(){
	for (int i = 0; i < 16; i++){
		if (player2Pieces[i]->getBoardPtr() != nullptr){
			player2Pieces[i]->getBoardPtr()->setClickable(true);
		}
	}
}

void Board::player2NoClick(){
	for (int i = 0; i < 16; i++){
		if (player2Pieces[i]->getBoardPtr() != nullptr){
			player2Pieces[i]->getBoardPtr()->setClickable(false);
		}
	}
}

void Board::boardNoClick(){
	for (int i = 0; i < 64; i++){
		boardSqr[i]->setClickable(false);
	}
}

void Board::boadResetCallBack(){
	for (int i = 0; i < 64; i++){
		boardSqr[i]->setCallBack(nullptr);
	}
}
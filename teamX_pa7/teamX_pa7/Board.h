#pragma once
#include "GameManager.h"

class Board
{
public:
	Board(GameManager & _manager);
	~Board();
private:
	ChessPiece * playerPieces[16];
	ChessPiece * enemyPieces[16];
	BoardSquare * boardSqr[64];
	BoardBorder * boardBdr[4];
};
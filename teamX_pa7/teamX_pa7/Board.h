#pragma once
#include <SFML/Graphics.hpp>
#include "GameManager.h"
#include "ChessPiece.h"
#include "BoardSquare.h"
#include "Pawn.h"
#include "Rook.h"
#include "Knight.h"
#include "Bishop.h"
#include "Queen.h"
#include "King.h"

class GameManager;

class Board
{
public:
	Board(GameManager * _manager);
	~Board();
private:
	GameManager * manager;
	void populateSqr();
	void populatePieces();

	sf::Texture redSqr;
	sf::Texture blackSqr;
	sf::Texture redPawn;
	sf::Texture redRook;
	sf::Texture redKnight;
	sf::Texture redBishop;
	sf::Texture redQueen;
	sf::Texture redKing;
	sf::Texture blackPawn;
	sf::Texture blackRook;
	sf::Texture blackKnight;
	sf::Texture blackBishop;
	sf::Texture blackQueen;
	sf::Texture blackKing;

	ChessPiece * player1Pieces[16];
	ChessPiece * player2Pieces[16];
	BoardSquare * boardSqr[64];
};
#pragma once
#include "Board.h"
#include "Pieces.h"
#include "Position.h"
#include <vector>




struct Move
{
	Position from;
	Position to;
	Piece capturedPiece;
};

class GameManager
{
public:
	enum class GameState { Playing, Checkmate, Stalemate, Draw, Quit };

	GameManager();

	void Initialize();
	void Run();
	bool IsGameOver() const;
	void ProcessTurn();
	GameState GetGameState() const;

private:
	Board board;
	Color currentPlayer;
	GameState gameState;
	std::vector<Move> moveHistory;

	
};




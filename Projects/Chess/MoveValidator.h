#pragma once
#include "Pieces.h"
#include "Position.h"

class Board;  

class MoveValidator
{
public:
	static bool IsValidMove(const Position& from, const Position& to, const Board& board);
	static bool IsPathClear(const Position& from, const Position& to, const Board& board);
	static bool CanPieceMove(PieceType type, const Position& from, const Position& to, const Board& board);
	static bool IsInCheck(Color color, const Board& board);
};


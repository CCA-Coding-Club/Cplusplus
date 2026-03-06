#pragma once
#include "Pieces.h"
#include <array>
#include <memory>

using namespace std;
class Board
{
public:
	Board();
	~Board();

	void InitializeBoard();
	void ClearBoard();

	bool CurrPiece(int row, int col, Piece& piece);
	bool MovePiece(int fromRow, int fromCol, int toRow, int toCol);
	bool RemovePiece(int row, int col);

	void PrintBoard();

	// Helper for MoveValidator
	const Piece* GetPieceAt(int row, int col) const;

private:
	// Static constexpr -> compile-time constant for array
	// unique_ptr -> smart pointer for automatic memory management
	static constexpr int BOARD_SIZE = 8;
	array<array<unique_ptr<Piece>, BOARD_SIZE>, BOARD_SIZE> board;

	char GetPieceSymbol(PieceType type, Color color);
};


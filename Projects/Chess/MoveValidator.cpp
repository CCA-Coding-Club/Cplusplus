#include "MoveValidator.h"
#include "Board.h"
#include <cmath>

using namespace std;

bool MoveValidator::IsValidMove(const Position& from, const Position& to, const Board& board)
{
	// Check if positions are valid
	if (!from.IsValid() || !to.IsValid())
		return false;

	// Check if there's a piece at the source
	const Piece* piece = board.GetPieceAt(from.row, from.col);
	if (piece == nullptr)
		return false;

	// Can't move to the same position
	if (from == to)
		return false;

	// Check if destination has a piece of the same color
	const Piece* destPiece = board.GetPieceAt(to.row, to.col);
	if (destPiece != nullptr && destPiece->color == piece->color)
		return false;

	// Check if the piece can make this move
	if (!CanPieceMove(piece->type, from, to, board))
		return false;

	// Check if path is clear (for sliding pieces)
	if (piece->type == PieceType::Rook || piece->type == PieceType::Bishop || piece->type == PieceType::Queen)
	{
		if (!IsPathClear(from, to, board))
			return false;
	}

	return true;
}

bool MoveValidator::CanPieceMove(PieceType type, const Position& from, const Position& to, const Board& board)
{
	int rowDiff = abs(to.row - from.row);
	int colDiff = abs(to.col - from.col);

	const Piece* piece = board.GetPieceAt(from.row, from.col);
	if (piece == nullptr)
		return false;

	switch (type)
	{
	case PieceType::Pawn:
	{
		int direction = (piece->color == Color::White) ? -1 : 1; // White moves up (negative), Black down (positive)
		int startRow = (piece->color == Color::White) ? 6 : 1;

		// Forward move
		if (from.col == to.col)
		{
			// One square forward
			if (to.row == from.row + direction && board.GetPieceAt(to.row, to.col) == nullptr)
				return true;

			// Two squares forward from starting position
			if (from.row == startRow && to.row == from.row + 2 * direction &&
				board.GetPieceAt(to.row, to.col) == nullptr &&
				board.GetPieceAt(from.row + direction, from.col) == nullptr)
				return true;
		}
		// Diagonal capture
		else if (colDiff == 1 && to.row == from.row + direction)
		{
			const Piece* destPiece = board.GetPieceAt(to.row, to.col);
			if (destPiece != nullptr && destPiece->color != piece->color)
				return true;
		}
		return false;
	}

	case PieceType::Knight:
		// L-shape: 2 squares in one direction, 1 in the other
		return (rowDiff == 2 && colDiff == 1) || (rowDiff == 1 && colDiff == 2);

	case PieceType::Bishop:
		// Diagonal moves only
		return rowDiff == colDiff && rowDiff > 0;

	case PieceType::Rook:
		// Horizontal or vertical moves only
		return (rowDiff == 0 && colDiff > 0) || (colDiff == 0 && rowDiff > 0);

	case PieceType::Queen:
		// Combination of rook and bishop
		return (rowDiff == colDiff && rowDiff > 0) || 
		       (rowDiff == 0 && colDiff > 0) || 
		       (colDiff == 0 && rowDiff > 0);

	case PieceType::King:
		// One square in any direction
		return rowDiff <= 1 && colDiff <= 1;

	default:
		return false;
	}
}

bool MoveValidator::IsPathClear(const Position& from, const Position& to, const Board& board)
{
	int rowDir = (to.row > from.row) ? 1 : (to.row < from.row) ? -1 : 0;
	int colDir = (to.col > from.col) ? 1 : (to.col < from.col) ? -1 : 0;

	int currentRow = from.row + rowDir;
	int currentCol = from.col + colDir;

	// Check all squares between from and to (excluding both endpoints)
	while (currentRow != to.row || currentCol != to.col)
	{
		if (board.GetPieceAt(currentRow, currentCol) != nullptr)
			return false;

		currentRow += rowDir;
		currentCol += colDir;
	}

	return true;
}

bool MoveValidator::IsInCheck(Color color, const Board& board)
{
	// TODO: Implement check detection (for later - more complex)
	return false;
}

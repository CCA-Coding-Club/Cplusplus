#include "Board.h"
#include "MoveValidator.h"
#include <iostream>
#include <cctype>

using namespace std;


Board::Board()
{
	// unique_ptr automatically initializes to nullptr (empty squares)
}

Board::~Board()
{
	// unique_ptr automatically cleans up memory
}

void Board::InitializeBoard()
{
	// Clear any existing pieces
	ClearBoard();

	// Setup Black pieces at row 0 
	board[0][0] = make_unique<Piece>(Piece{ PieceType::Rook, Color::Black });
	board[0][1] = make_unique<Piece>(Piece{ PieceType::Knight, Color::Black });
	board[0][2] = make_unique<Piece>(Piece{ PieceType::Bishop, Color::Black });
	board[0][3] = make_unique<Piece>(Piece{ PieceType::Queen, Color::Black });
	board[0][4] = make_unique<Piece>(Piece{ PieceType::King, Color::Black });
	board[0][5] = make_unique<Piece>(Piece{ PieceType::Bishop, Color::Black });
	board[0][6] = make_unique<Piece>(Piece{ PieceType::Knight, Color::Black });
	board[0][7] = make_unique<Piece>(Piece{ PieceType::Rook, Color::Black });


	// Setup Black pawns at row 1
	for (int col = 0; col < BOARD_SIZE; ++col)
	{
		board[1][col] = make_unique<Piece>(Piece{ PieceType::Pawn, Color::Black });
	}


	// Setup White pieces at row 7
	board[7][0] = make_unique<Piece>(Piece{ PieceType::Rook, Color::White });
	board[7][1] = make_unique<Piece>(Piece{ PieceType::Knight, Color::White });
	board[7][2] = make_unique<Piece>(Piece{ PieceType::Bishop, Color::White });
	board[7][3] = make_unique<Piece>(Piece{ PieceType::Queen, Color::White });
	board[7][4] = make_unique<Piece>(Piece{ PieceType::King, Color::White });
	board[7][5] = make_unique<Piece>(Piece{ PieceType::Bishop, Color::White });
	board[7][6] = make_unique<Piece>(Piece{ PieceType::Knight, Color::White });
	board[7][7] = make_unique<Piece>(Piece{ PieceType::Rook, Color::White });

	// Setup White pawns at row 6
	for (int col = 0; col < BOARD_SIZE; ++col)
	{
		board[6][col] = make_unique<Piece>(Piece{ PieceType::Pawn, Color::White });
	}

}

void Board::ClearBoard()
{
	for (int row = 0; row < BOARD_SIZE; ++row) {
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			board[row][col].reset(); // Sets to nullptr
		}
	}
}

bool Board::MovePiece(int fromRow, int fromCol, int toRow, int toCol)
{
	Position from(fromRow, fromCol);
	Position to(toRow, toCol);

	// Validate the move using MoveValidator
	if (!MoveValidator::IsValidMove(from, to, *this))
	{
		cout << "Invalid move! That piece cannot move there.\n";
		return false;
	}

	// Move the piece (capture if destination has a piece)
	board[toRow][toCol] = move(board[fromRow][fromCol]);
	
	return true;
}

bool Board::RemovePiece(int row, int col)
{
	if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
		return false;
	
	board[row][col].reset();
	return true;
}

bool Board::CurrPiece(int row, int col, Piece& piece)
{
	if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
		return false;
	
	if (board[row][col] == nullptr)
		return false;
	
	piece = *board[row][col];
	return true;
}

const Piece* Board::GetPieceAt(int row, int col) const
{
	if (row < 0 || row >= BOARD_SIZE || col < 0 || col >= BOARD_SIZE)
		return nullptr;
	
	return board[row][col].get();
}

void Board::PrintBoard()
{
	cout << "\n  a b c d e f g h\n";
	cout << " -----------------\n";

	for (int row = 0; row < BOARD_SIZE; ++row) {
		cout << (8 - row) << "|";
		for (int col = 0; col < BOARD_SIZE; ++col)
		{
			if (board[row][col] != nullptr)
			{
				char symbol = GetPieceSymbol(board[row][col]->type, board[row][col]->color);
				cout << symbol << " ";
			}
			else
			{
				cout << ". ";
			}
		}
		cout << "|" << (8 - row) << "\n";
	}

	cout << " -----------------\n";
	cout << "  a b c d e f g h\n\n";

}

char Board::GetPieceSymbol(PieceType type, Color color)
{
	// Uppercase = White, Lowercase = Black
	char symbol;

	switch (type)
	{
	case PieceType::King:symbol = 'K';break;
	case PieceType::Queen:symbol = 'Q';break;
	case PieceType::Rook:symbol = 'R'; break;
	case PieceType::Bishop:symbol = 'B'; break;
	case PieceType::Knight:symbol = 'N'; break;
	case PieceType::Pawn:symbol = 'P'; break;
	}

	// Make lowercase for black pieces
	if (color == Color::Black)
	{
		symbol = tolower(symbol);
	}
	return symbol;
}










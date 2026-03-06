#include "GameManager.h"
#include "MoveValidator.h"
#include <iostream>

using namespace std;

GameManager::GameManager() : currentPlayer(Color::White), gameState(GameState::Playing)
{
}

void GameManager::Initialize()
{
	board.InitializeBoard();
	currentPlayer = Color::White;
	gameState = GameState::Playing;
	moveHistory.clear();
	
	cout << "======================================\n";
	cout << "		Chess!        \n";
	cout << "======================================\n\n";
	cout << "Instructions:\n";
	cout << "  - Enter moves in chess notation ('e2 e4')\n";
	cout << "  - White pieces are uppercase (KQRBNP)\n";
	cout << "  - Black pieces are lowercase (kqrbnp)\n";
	cout << "  - Type 'quit' to exit\n\n";
}

void GameManager::Run()
{
	Initialize();
	board.PrintBoard();

	while (!IsGameOver())
	{
		ProcessTurn();
	}

	// Game over - display result
	cout << "\n======================================\n";
	cout << "           GAME OVER!                \n";
	cout << "======================================\n";
	
	switch (gameState)
	{
	case GameState::Checkmate:
		cout << "Checkmate! " << (currentPlayer == Color::White ? "Black" : "White") << " wins!\n";
		break;
	case GameState::Stalemate:
		cout << "Stalemate! Game is a draw.\n";
		break;
	case GameState::Draw:
		cout << "Game ended in a draw.\n";
		break;
	case GameState::Quit:
		cout << "Game ended by player.\n";
		break;
	default:
		break;
	}
}

void GameManager::ProcessTurn()
{
	// Display whose turn it is
	cout << "\n" << (currentPlayer == Color::White ? "White" : "Black") << "'s turn\n";
	cout << "----------------------------------------\n";

	Position from, to;
	bool validInput = false;

	// Keep asking for input until valid move is made
	while (!validInput)
	{
		cout << "Enter move (e.g., e2 e4): ";
		string input;
		getline(cin, input);

		// Check if player wants to quit
		if (PlayerInput::IsQuitCommand(input))
		{
			gameState = GameState::Quit;
			return;
		}

		if (!PlayerInput::ParseMove(input, from, to))
		{
			cout << "Invalid input format. Try again.\n";
			continue;
		}

		// Check if there's a piece at the source
		const Piece* piece = board.GetPieceAt(from.row, from.col);
		if (piece == nullptr)
		{
			cout << "No piece at " << from.ToChessNotation() << "! Try again.\n";
			continue;
		}

		// Check if the piece belongs to the current player
		if (piece->color != currentPlayer)
		{
			cout << "That's not your piece! Try again.\n";
			continue;
		}

		// Try to move the piece
		if (board.MovePiece(from.row, from.col, to.row, to.col))
		{
			// Record the move
			Move move;
			move.from = from;
			move.to = to;
			// TODO: Need to capture the piece before moving to record it properly
			// For now, leave it empty
			moveHistory.push_back(move);

			validInput = true;

			// Display the updated board
			board.PrintBoard();

			// Display the move
			cout << (currentPlayer == Color::White ? "White" : "Black") 
			     << " moved: " << from.ToChessNotation() 
			     << " -> " << to.ToChessNotation() << "\n";

			// Switch turns
			currentPlayer = (currentPlayer == Color::White) ? Color::Black : Color::White;
		}
		else
		{
			// MovePiece already prints error message
			cout << "Try again.\n";
		}
	}
}

bool GameManager::IsGameOver() const
{
	return gameState != GameState::Playing;
}

GameManager::GameState GameManager::GetGameState() const
{
	return gameState;
}

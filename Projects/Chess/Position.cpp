#include "Position.h"
#include <iostream>
#include <sstream>
#include <cctype>

using namespace std;

Position::Position() : row(-1), col(-1)
{

}

Position::Position(int row, int col) : row(row), col(col)
{

}

bool Position::IsValid() const
{
	return row >= 0 && row < 8 && col >= 0 && col < 8;
}

Position Position::FromChessNotation(const string& notation)
{
	// Check if notation is valid length
	if (notation.length() != 2)
		return Position(-1, -1);

	char file = tolower(notation[0]);  // Column: a-h
	char rank = notation[1];           // Row: 1-8

	// Validate input
	if (file < 'a' || file > 'h' || rank < '1' || rank > '8')
		return Position(-1, -1);

	// Convert to array indices
	int col = file - 'a';        // a=0, b=1, ..., h=7
	int row = 8 - (rank - '0');  // 8=0, 7=1, ..., 1=7

	return Position(row, col);
}

string Position::ToChessNotation() const
{
	if (!IsValid())
		return "Is Invalid";

	char file = 'a' + col;       // 0 = a, 1 = b, ..., 7 = h
	char rank = '8' - row;       // 0 = 8, 1 = 7, ..., 7 = 1

	return string(1, file) + string(1, rank);
}

bool Position::operator==(const Position& other) const
{
	return row == other.row && col == other.col;
}

bool Position::operator!=(const Position& other) const
{
	return !(*this == other);
}

bool PlayerInput::ParseMove(const string& input, Position& from, Position& to)
{
	istringstream iss(input);
	string fromStr, toStr;

	// Handle different input formats: "e2 e4", "e2-e4", "e2e4"
	if (input.find(' ') != string::npos)
	{
		// Format: "e2 e4"
		iss >> fromStr >> toStr;
	}
	else if (input.find('-') != string::npos)
	{
		// Format: "e2-e4"
		size_t pos = input.find('-');
		fromStr = input.substr(0, pos);
		toStr = input.substr(pos + 1);
	}
	else if (input.length() == 4)
	{
		// Format: "e2e4"
		fromStr = input.substr(0, 2);
		toStr = input.substr(2, 2);
	}
	else
	{
		return false;
	}

	// Convert to Position objects
	from = Position::FromChessNotation(fromStr);
	to = Position::FromChessNotation(toStr);

	// Check if both positions are valid
	return from.IsValid() && to.IsValid();
}

bool PlayerInput::GetPlayerMove(Position& from, Position& to)
{
	cout << "Enter move (e.g., e2 e4): ";
	string input;
	getline(cin, input);

	// Check if user wants to quit
	if (IsQuitCommand(input))
	{
		return false;
	}

	if (!ParseMove(input, from, to))
	{
		cout << "Invalid input format. Try again.\n";
		return false;
	}

	return true;
}

bool PlayerInput::IsQuitCommand(const string& input)
{
	// Convert to lowercase for case-insensitive comparison
	string lowerInput = input;
	for (char& c : lowerInput)
	{
		c = tolower(c);
	}
	
	// Check quit 
	return lowerInput == "quit";
}

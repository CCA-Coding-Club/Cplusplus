#pragma once
#include <string>

using namespace std;

struct Position
{
	int row;
	int col;

	Position();
	Position(int row, int col);

	bool IsValid() const;

	static Position FromChessNotation(const string& notation);
	string ToChessNotation() const;

	bool operator == (const Position& other) const;
	bool operator != (const Position& other) const;
};

namespace PlayerInput
{
	bool ParseMove(const string& input, Position& from, Position& to);
	bool GetPlayerMove(Position& from, Position& to);
	bool IsQuitCommand(const string& input);
}


// Sudoku Implimentation blueprint. Can take from cin, and cout.Can getand set 2d arrays.Has helper methods.

#pragma once
#include "puzzle.h"
#include <sstream>

class Sudoku : public Puzzle
{
public:	
	void print(ostream& where) const override;
	void input(istream& in) override;

	void fillSuduko(string numbs) override;

	// getters and setters
	int getArr(int row, int column) override;
	bool getFixed(int row, int column) override;

	void setArr(int row, int column, int value) override;
	void setFixed(int row, int column, bool value) override;

private:
	int sudoku_array[9][9] = { {0} };
	bool fixed[9][9] = { { false } }; // 1 is fixed, 0 is variable.
};
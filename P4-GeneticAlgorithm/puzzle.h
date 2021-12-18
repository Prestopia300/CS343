// Puzzle Interaface. Can take from cin, and cout. Can get and set 2d arrays. Has helper methods.

#pragma once
#include <iostream>
using namespace std;

class Puzzle
{
	friend ostream& operator<<(ostream& output, const Puzzle& P);
	friend istream& operator>>(istream& input, Puzzle& P);

public:	
	Puzzle& operator=(Puzzle& other);

	virtual void fillSuduko(string numbs) = 0;

	// getters and setters
	virtual int getArr(int row, int column) = 0;
	virtual bool getFixed(int row, int column) = 0;
	virtual void setArr(int row, int column, int value) = 0;
	virtual void setFixed(int row, int column, bool value) = 0; 

private:
	virtual void print(ostream& where) const = 0; 
	virtual void input(istream& in) = 0;
};
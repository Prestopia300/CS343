// Puzzle Implimentation. Can take from cin, and cout. Can set puzzle = to another puzzle. 

#include "puzzle.h"

ostream& operator<<(ostream& output, const Puzzle& puzzle)
{
	puzzle.print(output);
	return output;
}

istream& operator>>(istream& in, Puzzle& puzzle)
{
	puzzle.input(in);
	return in;
}

Puzzle& Puzzle::operator=(Puzzle& other) // this = other    // setting this's member variables (coppied from other)
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			setArr(i, j, other.getArr(i, j));
			setFixed(i, j, other.getFixed(i, j));
		}
	}
	return other;
}
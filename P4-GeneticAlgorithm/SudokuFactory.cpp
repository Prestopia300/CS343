#include "SudokuFactory.h"

shared_ptr<Puzzle> SudokuFactory::createPuzzle(shared_ptr<Puzzle> puzzle)
{
	return reproduction->makeOffspring(puzzle);
}
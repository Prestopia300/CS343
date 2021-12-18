#pragma once

#include "SudokuOffspring.h"
#include "PuzzleFactory.h"

class SudokuFactory : public PuzzleFactory
{
public:
	shared_ptr<Puzzle> createPuzzle(shared_ptr<Puzzle> puzzle) override;
private:
	shared_ptr<Reproduction> reproduction = make_shared<SudokuOffspring>();
};
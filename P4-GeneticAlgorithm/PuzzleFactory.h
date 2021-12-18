#pragma once
#include "Puzzle.h"
#include <iostream>
#include <memory>
using namespace std;

class PuzzleFactory
{
public:
	virtual shared_ptr<Puzzle> createPuzzle(shared_ptr<Puzzle> puzzle) = 0; 
};


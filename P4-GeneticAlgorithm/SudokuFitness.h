#pragma once
#include "Fitness.h"

class SudokuFitness : public Fitness
{	
public:
	int howFit(shared_ptr<Puzzle> puzzle) override;
};


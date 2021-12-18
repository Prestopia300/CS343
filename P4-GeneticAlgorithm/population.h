// Population Interface. Creates new generations for the genetic algorithm.

#pragma once
#include "puzzle.h"
#include <iostream>
using namespace std;

using Puzzle_Fitness_Pair = pair<int, shared_ptr<Puzzle>>; // used to sort from smallest fitness # to largest fitness #

class Population
{
public:
	virtual void createInitialPopulation() = 0;
	virtual void cull() = 0;
	virtual void newGeneration() = 0;
	virtual int bestFitness() = 0;
	virtual Puzzle_Fitness_Pair bestIndividual() = 0;
};
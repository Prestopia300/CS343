// SudokuPopulation Implimentation blueprint. Creates new generations for the genetic algorithm.

#pragma once
#include "sudoku.h"
#include "population.h"
#include "SudokuOffspring.h"

#include "SudokuFactory.h"
#include "SudokuFitness.h"

#include <iostream>
#include <vector>
using namespace std;


class SudokuPopulation : public Population
{
public:
	SudokuPopulation(shared_ptr<Puzzle> initialPuzzle, int populationSize);
	void createInitialPopulation() override;
	void cull() override;
	void newGeneration() override;
	int bestFitness() override;
	Puzzle_Fitness_Pair bestIndividual() override; // why *Puzzle ?
private: 
	
	int populationSize = 0;
	int maxGenerations = 0;
	int currentGeneration = 0;
	
	// how many to cull
	shared_ptr<Puzzle> initial_puzzle;
	vector<Puzzle_Fitness_Pair> population; 
	
	shared_ptr<Fitness> fitness_ = make_shared<SudokuFitness>(); // used for calculating fitness levels
	shared_ptr<PuzzleFactory> factory_ = make_shared<SudokuFactory>();
};
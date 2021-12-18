// SudokuPopulation Implimentation. Creates new generations for the genetic algorithm.

#include "SudokuPopulation.h"

SudokuPopulation::SudokuPopulation(shared_ptr<Puzzle> puzzle, int population_size)
{
	initial_puzzle = puzzle;
	populationSize = population_size;
}

void SudokuPopulation::createInitialPopulation()
{
	// create populationSize puzzles
	// adds them to a population vector

	for (int i = 0; i < populationSize; i++)
	{
		shared_ptr<Puzzle> new_sudoku = make_shared<Sudoku>();
		new_sudoku = factory_->createPuzzle(initial_puzzle);
		int fit = fitness_->howFit(new_sudoku);

		population.emplace_back(fit, new_sudoku);
	}
}

void SudokuPopulation::cull() // Culls (deletes) 90% off the puzzles in the current generation
{	
	sort(population.begin(), population.end());

	double start = populationSize * (1 - 0.9);  
	start = max(1, (int)start + 1); // need atleast 1 in population
	population.erase(population.begin() + start, population.end());
}

void SudokuPopulation::newGeneration() // Creates new generation based off of the best puzzles of the previous generation
{
	
	int currIdx = 0; // creates puzzles based of of the remaining puzzles from the last generation
	int maxIdx = (int)population.size();

	while (population.size() < populationSize)
	{
		shared_ptr<Puzzle> p = factory_->createPuzzle(population[currIdx].second);
		population.emplace_back(fitness_->howFit(p), p); // pair of fitness number and puzzle
		currIdx++;
		currIdx %= maxIdx;
	}
}

int SudokuPopulation::bestFitness()
{
	auto it = min_element(population.begin(), population.end());
	return it->first;
}

Puzzle_Fitness_Pair SudokuPopulation::bestIndividual()
{
	return *min_element(population.begin(), population.end());
}

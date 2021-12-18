// Main and Genetic Algorithm. Takes in a populationSize and maxGeneration from cmd line/terminal. Uses SudokuPopulation to impliment the genetic algorithm and outputs the best sudoku.


#include <iostream>
#include <memory>
#include "sudoku.h"
#include "SudokuOffspring.h"
#include "SudokuFactory.h"
#include "SudokuFitness.h"

#include "SudokuPopulation.h"

using namespace std;

int main(int argc, char** argv) {
	
	if (argc != 3) {
       cerr << "Usage: " << argv[0] << " <POPULATION SIZE> <MAX GENERATION>\n"; // crr is error output. Should input like this <<
       return 1;
    }

	shared_ptr<Puzzle> sudoku = make_shared<Sudoku>();

	cin >> *sudoku;
	cout << "Initial Sudoku : " << endl;
	cout << *sudoku;

	cout << "\n\n-------------------\n\n";
	
	int populationSize = 100;
	int maxGeneration = 40;
	SudokuPopulation s_pop(sudoku, populationSize);
	
	s_pop.createInitialPopulation();
	cout << "Population 0 best fitness: " << s_pop.bestFitness() << endl;

	Puzzle_Fitness_Pair best{ numeric_limits<int>::max(), nullptr };

	for (int i = 0; i < maxGeneration; i++)
	{
		if (s_pop.bestFitness() == 0) {
			best = s_pop.bestIndividual();
			break;
		}
		if (s_pop.bestFitness() < best.first) {
			best = s_pop.bestIndividual();
		}
		//cout << "Generation " << i+1 << " best fitness: " << s_pop.bestFitness() << endl;
		s_pop.cull();
		s_pop.newGeneration();
	}
	cout << "Result is a sudoku with a fittness score of " << s_pop.bestFitness() << endl;
	
	cout << *s_pop.bestIndividual().second;
}
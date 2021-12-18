/**
 * Main Genetic Algorithm Class
 */

#pragma once

#include "Puzzle.h"
#include "Population.h"
#include <limits>
#include <memory>
using namespace std;

template<typename T>
class RunGeneticAlgorithm {
public:
    RunGeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle>& initial);
    Puzzle_Fitness_Pair run();

private:
    int max_generation; // max number of generations
    shared_ptr<Population> population; // population class
};

template<typename T>
RunGeneticAlgorithm<T>::RunGeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle>& initial)
    : max_generation(max_generation), population(make_shared<T>(initial, population_size)) { }

// run genetic algorithm
template<typename T>
Puzzle_Fitness_Pair RunGeneticAlgorithm<T>::run() {
    Puzzle_Fitness_Pair best{ numeric_limits<int>::max(), nullptr };

    // run for max_generation times
    for (int k = 0; k < max_generation; ++k) {
        // get current best individual
        Puzzle_Fitness_Pair current_best = population->bestIndividual();
        // if found the solution
        if (current_best.first == 0) {
            best = current_best;
            break;
        }
        // update best individual
        if (current_best.first < best.first) {
            best = current_best;
        }
        // cull 90% individuals
        population->cull();
        // make new generation
        population->newGeneration();
    }

    return best;
}

///**
// * Main Genetic Algorithm Class
// */
//
//#pragma once
//
//#include "Puzzle.h"
//#include "Population.h"
//#include <limits>
//#include <memory>
//using namespace std;
//
//class RunGeneticAlgorithm {
//public:
//    RunGeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle>& initial);
//    Puzzle_Fitness_Pair run();
//
//private:
//    int max_generation_; // max number of generations
//    shared_ptr<Population> population; // population class
//};
//
//RunGeneticAlgorithm::RunGeneticAlgorithm(int max_generation, int population_size, shared_ptr<Puzzle>& initial)
//{
//    max_generation_ = max_generation;
//    population = make_shared<SudokuPopulation>(initial, population_size);
//}
//   
//
//// run genetic algorithm
//Puzzle_Fitness_Pair RunGeneticAlgorithm::run() {
//    Puzzle_Fitness_Pair best/*{ numeric_limits<int>::max(), nullptr }*/;
//
//    // run for max_generation times
//    for (int k = 0; k < max_generation_; ++k) {
//        // get current best individual
//        //Puzzle_Fitness_Pair current_best = population->bestIndividual();
//        // if found the solution
//        if (population->bestFitness() == 0) {
//            best = population->bestIndividual();
//            break;
//        }
//        // update best individual
//        if (population->bestFitness() < best.first) {
//            best = population->bestIndividual();
//        }
//        // cull 90% individuals
//        population->cull();
//        // make new generation
//        population->newGeneration();
//    }
//
//    return best;
//}
  
//<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

// run genetic algorithm

//Puzzle_Fitness_Pair RunGeneticAlgorithm::run() {
//    Puzzle_Fitness_Pair best{numeric_limits<int>::max(), nullptr};
//
//    // run for max_generation times
//    for (int k=0; k< max_generation_; ++k) {
//        // get current best individual
//        Puzzle_Fitness_Pair current_best = population->bestIndividual();
//        // if found the solution
//        if (current_best.first == 0) {
//            best = current_best;
//            break;
//        }
//        // update best individual
//        if (current_best.first < best.first) {
//            best = current_best;
//        }
//        // cull 90% individuals
//        population->cull();
//        // make new generation
//        population->newGeneration();
//    }
//
//    return best;
//}

//max_generation_ = max_generation;
//population = make_shared<SudokuPopulation>(initial, population_size);
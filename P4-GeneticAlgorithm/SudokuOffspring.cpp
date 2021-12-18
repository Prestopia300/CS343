// SudokuOffspring Implimentation. Makes an offspring from a parent puzzle, with the 5% chance of changing each non-fixed element of the sudoku.

#include "Sudoku.h"
#include "SudokuOffspring.h"
#include <random>
#include <functional>
#include <memory>
using namespace std;

shared_ptr<Puzzle> SudokuOffspring::makeOffspring(shared_ptr<Puzzle>& puzzle) // was shared_ptr<Puzzle>
{
    const int prob = 5;
    shared_ptr<Sudoku> sudoku = make_shared<Sudoku>();

    for (int i = 0; i < 9; ++i) for (int j = 0; j < 9; ++j) {
        int v = puzzle->getArr(i, j);
        bool fixed = puzzle->getFixed(i, j);
        int random = rand() % 100; // rand() creates random numb from any integer
        int replace = (rand() % 9) + 1;

        if (v == 0 || (random < prob && !fixed)) { // was rng_100()
            v = replace;
        }
        sudoku->setArr(i, j, v); // fixed is already set
        sudoku->setFixed(i, j, fixed);

    }
    return sudoku;
}
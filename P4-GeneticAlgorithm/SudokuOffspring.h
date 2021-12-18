// SudokuOffspring Implimentation blueprint. Makes an offspring from a parent puzzle, with the 5% chance of changing each non-fixed element of the sudoku.

#pragma once
#include "Reproduction.h"

#include <random>
#include <functional>
#include <memory>
#include <iostream>
using namespace std;

class SudokuOffspring : public Reproduction
{
public:
	shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle>& puzzle) override; // was Puzzle&
};


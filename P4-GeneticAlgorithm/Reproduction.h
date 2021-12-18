#pragma once
#include "puzzle.h"
#include <iostream>
using namespace std;

class Reproduction
{
public:
	virtual shared_ptr<Puzzle> makeOffspring(shared_ptr<Puzzle>& puzzle) = 0; // was shared_ptr<Puzzle>
};
#pragma once

#include "puzzle.h"
#include <iostream>
using namespace std;

class Fitness
{
public:
	virtual int howFit(shared_ptr<Puzzle> puzzle) = 0;
};


#pragma once
#include "caller.h"
#include "PriorityQueue.h"

#include <iostream>
#include <vector>
#include <random>
#include <cmath>
using namespace std;
class CallProcessor
{
public:
	CallProcessor();
	CallProcessor(int numOfCallTakers, int legitCallsPerhour, int aveSecondsPerLegitCall, int numOfBots); 

	//~CallProcessor();

	//int AverageLegitCallServiceTime();
	void RunSimulation();
	void BotCallGenerator(int numOfBots);
	void LegitamateCallGenerator();
	void printGeneratedCalls();

private:
	int numberOfCallTakers;
	double legitCallsPerHour;
	double averageSecondsPerLegitCall;
	int numberOfBots;
	
	vector<Caller> generated_calls;

	int clock_time_ = 0;
};


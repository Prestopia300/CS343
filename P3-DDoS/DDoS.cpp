// DDoS.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "PriorityQueue.h"
#include "caller.h"
#include "CallProcessor.h"
#include <iostream>
using namespace std;

int main(int argc, char* argv[]) // run multiple times for differing numbers of bots
{
    // takes only 4 argument from command line
    if (argc == 5)
    {
        int numOfCallTakers = atoi(argv[1]);
        int legitCallsPerhour = atoi(argv[2]);
        int aveSecondsPerLegitCall = atoi(argv[3]);
        int numOfBots = atoi(argv[4]);
        cout << numOfCallTakers << "-" << legitCallsPerhour << "-" << aveSecondsPerLegitCall << "-" << numOfBots << endl;
        cout << "-Service time Average- Bots = " << numOfBots << endl;
        CallProcessor callp(numOfCallTakers, legitCallsPerhour, aveSecondsPerLegitCall, numOfBots);
        callp.RunSimulation(); // number of call_takers, number of bots

    }
    else
    {
        cout << "Please input only 4 arguments." << endl;
    }

    //CallProcessor cp(28, 887, 120, 0);

    //cout << "-Service time Average- Bots = 0" << endl;
    //cp.RunSimulation(28, 0); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 100" << endl;
    //cp.RunSimulation(28, 100); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 1000" << endl;
    //cp.RunSimulation(28, 1000); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 2000" << endl;
    //cp.RunSimulation(28, 2000); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 3000" << endl;
    //cp.RunSimulation(28, 3000); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 6000" << endl;
    //cp.RunSimulation(28, 6000); // number of call_takers, number of bots

    //cout << "\n-Service time Average- Bots = 10000" << endl;
    //cp.RunSimulation(28, 10000); // number of call_takers, number of bots

    return 0;
}
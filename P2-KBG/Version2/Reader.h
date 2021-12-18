// Reader.h contains the blueprint for reader, which takes in a file, differentiates between actors and movies, and processes them
// so that adjcent actors can be added to the graph that is initialized in this class.

#pragma once

#include "Graph.h"
#include <string>
#include <fstream>
#include <map>

#include <iostream>
using namespace std;

class Reader
{
public:
	Reader();

	void readInFile(string str);
	bool buildGraph();

	string getActor(string line);
	string getMovie(string line);

private:
	vector<string> actor_index_; // actor name container with strings, access with index

	map<string, vector<int>> movies_to_actors_; // stores movie intex with vector of all actors that appeared in that movie map of movies (string key) to actors (int value)
};
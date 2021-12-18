//Graph.h contains the blueprint for the graph class, which creates an adjacency list graph and outputs the kevin bacon numbers of all actors

#pragma once

#include <iostream>
#include <list>
#include <vector>

#include <utility>
#include <set>

using namespace std;

class Graph
{
private:

	list<pair<int, int>>* adjacency_list;
	int vertex_number_; // size of adjacency_list 
	int kevin_bacon_vertex = -1;
	void clearDuplicates();

public:
	Graph(int vertex_number);
	void build(const vector<int>& vector_actor);
	void addEdge(int origin, int destination);

	void displayAdj();
	bool getKevinBaconIndex(const vector<string>& actor_index);
	bool findBaconNumber(const vector<string>& actor_index);
	//int BFS(int start);
	void shortestPath(int start);
};
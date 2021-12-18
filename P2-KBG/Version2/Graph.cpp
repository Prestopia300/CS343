//Graph.cpp contains the methods for the graph class, which creates an adjacency list graph and outputs the kevin bacon numbers of all actors

#include "Graph.h"
//#define INF 1000000;




Graph::Graph(int vertex_number)
{
	vertex_number_ = vertex_number;  // how many actors there are
	
	
	//list<pair<int, int>>* adjacency_list
	adjacency_list = new list<pair<int, int>>[vertex_number_]; // initialize the list with size
}

void Graph::build(const vector<int>& vector_actor) // takes an actor index from a movie
{
	int actor_index_from;
	int actor_index_to;

	// construct adjacency list
	for (int i = 0; i < vector_actor.size(); i++)
	{
		actor_index_from = vector_actor[i];

		for (int j = 0; j < vector_actor.size(); j++)
		{
			actor_index_to = vector_actor[j];
			addEdge(actor_index_from, actor_index_to);
		}
	}
	clearDuplicates();
}

void Graph::addEdge(int origin, int destination)
{
	if (origin != destination) // takes care of self loops
	{
		adjacency_list[origin].push_back(make_pair(destination, 1)); // weight is always 1
		adjacency_list[destination].push_back(make_pair(origin, 1));
	}
}

void Graph::clearDuplicates()
{
	for (int i = 0; i < vertex_number_; i++)
	{
		adjacency_list[i].sort();
		adjacency_list[i].unique();
	}
}

void Graph::displayAdj()
{
	for (int i = 0; i < vertex_number_; i++)
	{
		cout << "adj[" << i << "]: ";
		for (auto actor_num : adjacency_list[i])
		{
			cout << "->" << actor_num.first; // is it first??
		}
		cout << endl;
	}
}

bool Graph::getKevinBaconIndex(const vector<string>& actor_name) // looks for "Kevin Bacon" vector
{
	for (int i = 0; i < actor_name.size(); i++) // finds if string is in actor_name
	{
		size_t found = actor_name[i].find("Bacon, Kevin (I)");
		if (found != string::npos)
		{
			kevin_bacon_vertex = i;
			//cout << "K_B_V = " << i << endl;
			return true;
		}
	}
	cout << "Bacon, Kevin (I) is not found in the database." << endl;
	return false;
}

bool Graph::findBaconNumber(const vector<string>& actor_index)
{
	return false;
}

//// BFS algorithm
//int Graph::BFS(int s)
//{
//	int target = kevin_bacon_vertex;
//	//cout << "kevin_bacon_vertex = " << target << endl;
//
//	bool* visited = new bool[vertex_number_];
//	for (int i = 0; i < vertex_number_; i++)
//	{
//		visited[i] = false;
//	}
//
//	list<int> queue;
//
//	visited[s] = true;
//	queue.push_back(s);
//	
//
//	/*int count = 0;
//	if (s == target)
//	{
//		return count;
//	}*/
//
//
//	// To keep required answer
//	int ans = 99999999;
//	
//	// Distance s vertex to Kevin Bacon's is zero
//	int dist = 0;
//
//	// Count the good vertices
//	int good = 0;
//
//
//	while (!queue.empty()) {
//		s = queue.front();
//		queue.pop_front();
//
//
//		//count++;
//		for (auto i = adjacency_list[s].begin(); i != adjacency_list[s].end(); i++)
//		{
//
//			if (!visited[*i]) {
//				//cout << "Visit and euqueue " << *i << endl;
//
//				visited[*i] = true;
//				queue.push_back(*i);
//
//				if (*i == target)
//				{
//					//if (count > 2) // takes care of searching for multiple adjacent verticies
//					//{
//					//	count--;
//					//}
//					//return count;
//				}
//			}
//		}
//	}
//	return -1; // changes to inifinity
//}


// BFS algorithm
void Graph::shortestPath(int s)
{
	//int target = kevin_bacon_vertex;
	////cout << "kevin_bacon_vertex = " << target << endl;

	//bool* visited = new bool[vertex_number_];
	//for (int i = 0; i < vertex_number_; i++)
	//{
	//	visited[i] = false;
	//}

	//list<int> queue;

	//visited[s] = true;
	//queue.push_back(s);


	//start from Youtube video (C++ Data Structures: Dijkstra's Algorithm)
	
	//Create set to store vertices
	// User this to extract the shortest path
	set<pair<int, int>> extract_set;

	// Vector for distances
	// All paths are initilized to a large value
	vector<int> distances(vertex_number_, 1000000);

	// Insert the entry point to the set
	// Initialize distance to 0
	extract_set.insert(make_pair(0, s));
	distances[s] = 0;

	// Continue untill all shortest distances are finalized
	while (!extract_set.empty()) {
		// Extract the minimum distances
		pair<int, int> tmp = *(extract_set.begin());
		extract_set.erase(extract_set.begin());

		// Get the vertex number
		int u = tmp.second;

		// Go over the adjacency list
		for (auto i = adjacency_list[u].begin(); i != adjacency_list[u].end(); i++) // was s now u 
		{
			// Get the vertex (not weight, which is always 1)
			int v = (*i).first;
			int weight = (*i).second;

			// check if we have found a shorter path to v
			if (distances[v] > distances[u] + weight) {

				// Remove the current distance if it is in the set
				if (distances[v] != 1000000) {
					extract_set.erase(extract_set.find(make_pair(distances[v], v)));
				}

				// Update the distance
				distances[v] = distances[u] + weight;
				extract_set.insert(make_pair(distances[v], v));
			}
		}
	}

	cout << "Minimum distences from vertex: " << s << endl;
	for (int i = 0; i < vertex_number_; i++)
	{
		cout << "Vertex: " << i << "\tDistance: " << distances[i] << endl;
	}
}
//Graph.cpp contains the methods for the graph class, which creates an adjacency list graph and outputs the kevin bacon numbers of all actors

#include "Graph.h"

Graph::Graph(int vertex_number)
{
	vertex_number_ = vertex_number;  // how many actors there are
	adjacency_list = new list<int>[vertex_number_]; // initialize the list with size
}

void Graph::build(const vector<int>& vector_actor) // takes an actor index from a movie
{
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
		adjacency_list[origin].push_back(destination);
		adjacency_list[destination].push_back(origin);
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
			cout << "->" << actor_num;
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

// BFS algorithm
int Graph::BFS(int s)
{
	int target = kevin_bacon_vertex;
	//cout << "kevin_bacon_vertex = " << target << endl;

	bool* visited = new bool[vertex_number_];
	for (int i = 0; i < vertex_number_; i++)
	{
		visited[i] = false;
	}

	list<int> queue;

	int count = 0;

	visited[s] = true;
	queue.push_back(s);

	if (s == target)
	{
		return count;
	}


	while (!queue.empty()) {
		s = queue.front();
		queue.pop_front();


		count++;
		for (auto i = adjacency_list[s].begin(); i != adjacency_list[s].end(); i++)
		{
			
			if (!visited[*i]) {
				//cout << "Visit and euqueue " << *i << endl;
				
				visited[*i] = true;
				queue.push_back(*i);

				if (*i == target)
				{
					if (count > 2) // takes care of searching for multiple adjacent verticies
					{
						count--;
					}
					return count;
				}
			}
		}
	}
	return -1; // changes to inifinity
}

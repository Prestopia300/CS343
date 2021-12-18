/// Reader.cpp contains the blueprint for reader, which takes in a file, differentiates between actors and movies, and processes them
// so that adjcent actors can be added to the graph that is initialized in this class.

#include "Reader.h"

Reader::Reader()
{
}

void Reader::readInFile(string str)
{
	string line;
	fstream file;
	
	file.open(str);
	if (file.is_open())
	{
		string actor;
		string movie;
		int i = -1;

		while (getline(file, line)) // Overview: push_back index of actor/movie
		{
			if (!line.empty()) 
			{
				if (line.front() != '\t') // Line starting with actor names
				{
					++i; // i = 0 as start
					actor = getActor(line);
					movie = getMovie(line);

					actor_index_.push_back(actor); // actor name container
					movies_to_actors_[movie].push_back(i); // map of movies to actors
				}
				else // other movies the actor was in
				{
					// checks for duplicate movies/tv shows
					string previous_movie = movie;
					string current_movie = getMovie(line);
					if (current_movie != previous_movie)
					{
						movie = current_movie;
						movies_to_actors_[movie].push_back(i); // actor index is pushed to all other movies they appear in, stored in vector<int> value of map
					}
				}
			}
		}
		file.close();
		buildGraph();
	}
	else
	{
		cout << str << " file not found." << endl; // error message if invalid file
	}
}

bool Reader::buildGraph() // builds and displays's graph and it's bacon numbers
{
	Graph actor_graph(actor_index_.size());
	
	// prints out the map of actors_to_movies_ 
	for (auto& i : movies_to_actors_)
	{
		string const& movie = i.first; // iterator to key (movie name)
		vector<int> actor_i = i.second; // iterator to value (actor index)

		actor_graph.build(actor_i); // builds Adjlst with actor vector for each index in movies_to_actors_
	}
	
	cout << "-----------------------\n" << endl; // display's adjacency_list
	cout << "build_graph: " << endl;
	cout << "----------------------" << endl;

	actor_graph.displayAdj();
	cout << "displayAdj end" << endl;


	actor_graph.getKevinBaconIndex(actor_index_); 
	
	int size = actor_index_.size();
	for (int index = 0; index < actor_index_.size(); index++)
	{
		cout << actor_index_[index] << " =\t";  //actor_index << " = ";
		int bacon_num = actor_graph.BFS(index);
		if (bacon_num == -1)
		{
			cout << "Infinity" << endl;
		} 
		else {
			cout << bacon_num << endl;
		}
	}
	return true;
}


string Reader::getActor(string line) // get's actor string from input line
{
	string s = line;
	string delimiter = "\t";

	size_t pos = 0;
	string actor;
	while ((pos = s.find(delimiter)) != string::npos) { 
		actor = s.substr(0, pos);
		s.erase(0, s.npos);
	}

	int last = actor.size() - 1; // deletes extra space(s) at end
	while (last >= 0 && actor[last] == ' ')
		--last;
	actor = actor.substr(0, last + 1);

	return actor;
}

string Reader::getMovie(string line) // gets movie string from input line
{
	string s = line;
	string delimiter = "\t";

	size_t pos = 0;
	string movie = "";
	while ((pos = s.find(delimiter)) != string::npos) {
		movie = s.erase(0, pos + delimiter.length());
	}


	// bad chars: [any text], <any text>, (non numerical info)
	if (movie.find('['))
	{
		if (movie.find(']') && (movie.find('[') < movie.find(']')))
		{
			movie.erase(movie.find('['), string::npos);
		}
	}
	// <>
	if (movie.find('<'))
	{
		if (movie.find('>') && (movie.find('<') < movie.find('>')))
		{
			movie.erase(movie.find('<'), string::npos);
		}
	}
	if (movie.find('{'))
	{
		if (movie.find('}') && (movie.find('{') < movie.find('}')))
		{
			movie.erase(movie.find('{'), string::npos);
		}
	}

	// (non-numerical)
	string forParen = "(";
	string backParen = ")";
	if (movie.find(forParen) != string::npos) // check if movie contains (
	{
		// first ()
		size_t found = movie.find(forParen); // (
		int index1;
		if (found != string::npos)
		{
			index1 = found + 1;
		}
		size_t found2 = movie.find(backParen); // )
		int index2;
		if (found2 != string::npos)
		{
			index2 = found2 - 1;
		}

		int len1 = index2 - index1 + 1; //  between
		string betweenParen = movie.substr(index1, len1);
		
		bool has_only_digits = true; // check if num
		for (size_t n = 0; n < betweenParen.length(); n++)
		{
			if (!isdigit(betweenParen[n]))
			{
				has_only_digits = false;
				break;
			}
		}
		if (!has_only_digits)
		{
			movie.erase(movie.find('('), string::npos);
		}

		// second () - this will only get to second.
		char arr[] = "("; // (
		found = movie.find(arr, found + 1);
		if (found != string::npos)
		{
			index1 = found + 1;
		}
		char arr2[] = ")"; // )
		found2 = movie.find(arr2, found2 + 1);
		if (found2 != string::npos)
		{
			index2 = found2 - 1;
		}

		int len2 = index2 - index1 + 1; //  between
		betweenParen = movie.substr(index1, len2);

		has_only_digits = true; // check if num
		for (size_t n = 0; n < betweenParen.length(); n++)
		{
			if (!isdigit(betweenParen[n]))
			{
				has_only_digits = false;
				break;
			}
		}
		if (!has_only_digits)
		{
			movie.erase(found, string::npos);
		}
	}

	int last = movie.size() - 1; // deletes extra space(s) at end
	while (last >= 0 && movie[last] == ' ')
		--last;
	movie = movie.substr(0, last + 1);

	int first = 0; // deletes extra space(s) at beginning
	while (first <= movie.size()-1 && movie[first] == ' ')
		++first;	
	int leng3 = movie.size() - first;
	movie = movie.substr(first, leng3); 


	return movie;
}
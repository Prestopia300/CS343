// KevinBaconGame.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <unordered_map>
#include "Graph.h"
#include "Reader.h"

using namespace std;


int main(int argc, char* argv[])
{
	Reader file;
	string in_file;

	// takes only one argument from command line

	in_file = "Bacon.txt";
	//cin >> in_file;
	file.readInFile(in_file);

	/*if (argc == 2)
	{
		in_file = argv[1];
		file.readInFile(in_file);
	}
	else
	{
		cout << "Please input only one file name." << endl;
	}*/
}
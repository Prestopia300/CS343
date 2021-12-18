#include "Concordance.h"

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>
using namespace std;

Concordance::Concordance(string corpus, string stopwords)
{
	corpusFile = corpus;
	stopwordsFile = stopwords;
}


void Concordance::processStopwordsFile() // reads stopwords into a vector
{
	ifstream MyReadFile;
	MyReadFile.open(stopwordsFile);

	if (MyReadFile.is_open()) {
		cout << "Read file: " << stopwordsFile << endl;
		string line;

		while (getline(MyReadFile, line)) { // gets line of stopwords

			stringstream ss(line);
			string item;
			while (getline(ss, item, ' ')) // Uses ' ' to seperate words
			{
				if (item != "") // not empty
				{
					stopwords.push_back(item);
				}
			}
		}
		MyReadFile.close();
	}
}

bool Concordance::checkStopwords(string word) // Checks if a given word is a stopword
{
	for (int i = 0; i < stopwords.size(); i++)
	{
		if (word == stopwords[i])
		{
			return true;
		}
	}
	return false;
}

void Concordance::processCorpusFile() // reads and cleans corpus words into a vector
{	
	ifstream MyReadFile;
	MyReadFile.open(corpusFile);

	if (MyReadFile.is_open()) {
		cout << "Read file: " << corpusFile << endl;
		string line;

		while (getline(MyReadFile, line)) { // gets line of corpusWords
			stringstream ss(line);
			string item;
			while (getline(ss, item, ' ')) // Uses ' ' to seperate words
			{				
				string cleanedWord = trimWord(item);
				
				if (item != "")
				{
					corpusWords.push_back(cleanedWord);
				}
			}
		}
		MyReadFile.close();
	}
}

void Concordance::execute() // creates and inserts contexts into the binary tree, displaying that tree at the end 
{
	BinarySearchTree tree;
	/*tree.Insert("cat", "there was a.", "and he was fat");
	tree.Insert("rat", "can a.", "eat bugs?");
	tree.Insert("cat", "this is cat.", "number 2");
	tree.Insert("cat", "this is cat.", "number 3");
	tree.Insert("rat", "r.at", "number 2");
	tree.Insert("aat", "a.at", "lesser than cat");
	tree.Insert("aat", "aa.t", "lesser than cat 2");*/

	for (int i = 0; i < corpusWords.size(); i++)
	{
		string before = "";
		string after = "";
		string key = corpusWords[i];
		int maxBeforeSize = 0;
	
		if (checkStopwords(corpusWords[i]) == false) // keyword can't be a stopword
		{
			if (i < 5) //before
			{
				for (int j = 0; j < i; j++)
				{
					if (checkStopwords(corpusWords[j]) == false)
					{
						before += corpusWords[j] + " ";
					}
				}
			}
			else
			{
				for (int k = i - 5; k < i; k++)
				{
					if (checkStopwords(corpusWords[k]) == false)
					{
						before += corpusWords[k] + " ";
					}
				}
			}

			if (i >= corpusWords.size() - 5) // after
			{
				for (int l = i + 1; l < corpusWords.size(); l++)
				{
					if (checkStopwords(corpusWords[l]) == false)
					{
						after += corpusWords[l] + " ";
					}
				}
			}
			else
			{
				for (int m = i + 1; m < i + 6; m++)
				{
					if (checkStopwords(corpusWords[m]) == false)
					{
						after += corpusWords[m] + " ";
					}
				}
			}	
			if (key != "")
			{
				tree.Insert(key, before, after);
			}
		}
	}
	tree.Display();
}

void Concordance::outputCorpusWords() //displays all corpus words, and number of stopwords
{
	int counter = 0;
	for (int i = 0; i < corpusWords.size(); i++)
	{
		if (checkStopwords(corpusWords[i]))
		{
			counter += 1;
		}
		cout << corpusWords[i] << " ";
	}
	cout << "\n\n\nnumber of stopwords = " << counter << endl;
}

void Concordance::outputStopwords() // displays all stopwords
{
	for (int i = 0; i < stopwords.size(); i++)
	{
		cout << stopwords[i] << " ";
	}
}

string Concordance::trimWord(string &word) // removes punctuation from beginning and end of a word, and converts capital letters to lowercase
{	
	while (word != "" && ispunct(word.front())) // stops if word is empty or if front isn't a punctuation char
	{
		word.erase(word.begin()); 
	}
	while (word != "" && ispunct(word.back())) // stops if word is empty or if back isn't a punctuation char
	{
		word.pop_back();
	}

	transform(word.begin(), word.end(), word.begin(), tolower);

	return word;
}

#pragma once
#include "LinkedList.h"
#include "Context.h"
#include "BinarySearchTree.h"
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Concordance
{
public:
	Concordance(string corpus, string stopwords);

	void processStopwordsFile();
	bool checkStopwords(string word);

	void processCorpusFile();
	void execute();

	void outputCorpusWords();
	void outputStopwords();

	string trimWord(string& word);

private:
	string corpusFile = "" ;
	string stopwordsFile = "";

	vector<string> corpusWords;
	
	vector<string> stopwords;

};


// ConcordanceGenerator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "Concordance.h"
#include <iostream>
using namespace std;


int main()
{
    string con;// = "C:\Users\Preston\Downloads\corpus.txt";
    cin >> con;

    string sto;// = "C:\Users\Preston\Downloads\stopwords.txt"
    cin >> sto;

    Concordance c(con,sto);
    c.processStopwordsFile();
    c.processCorpusFile();

    c.execute();
}


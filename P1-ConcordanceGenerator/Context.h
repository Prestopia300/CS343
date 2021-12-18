#pragma once
#include <iostream>
#include <iomanip>
using namespace std;

class Context
{
	
public:
	Context();
	
	string getBefore();
	string getKeyword();
	string getAfter();
	int getMaxBeforeTextSize();

	void setBefore(string before);
	void setKeyword(string key);
	void setAfter(string after);
	void setMaxBeforeTextSize(int beforeSize);

	void printContext() const;
	
private:
	string beforeText;
	string afterText;
	string keywordText; 
	int maxBeforeTextSize = 0;
};


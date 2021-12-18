#pragma once
#include "Context.h"
#include <iostream>
using namespace std;

class LinkedList
{
private:
	struct Node
	{
		Context* data;
		Node* next = nullptr;
	};
	Node* head = nullptr;
	Node* tail = nullptr;
	string key;

public:
	LinkedList();
	~LinkedList();
	void insert(string before, string after);
	void clear();
	void printList();
	int getMaxBeforeSize();
	void setMaxBeforeSize(int max);

	void setKey(string keyString);
	string getKey();
};


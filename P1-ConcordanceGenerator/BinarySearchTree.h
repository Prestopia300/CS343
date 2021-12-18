#pragma once
#include <iostream>
#include "LinkedList.h"
using namespace std;

class BinarySearchTree
{
private:
	struct Node
	{
		string key;
		LinkedList* contexts/* = new LinkedList*/;
		Node* right = nullptr;
		Node* left = nullptr;
	};
	Node* root = nullptr;


public:
	BinarySearchTree();
	~BinarySearchTree();

	bool Insert(string key, string beforeCon, string afterCon); // was LinkedList* the_list
	
	void Display();
	void Display(Node* curr);

	int getMaxBeforeSize();
	int getMaxBeforeSize(Node* curr, int& max);

	void Flush();
	void Flush(Node* curr);

	bool isEmpty() const;

};
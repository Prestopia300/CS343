#include "BinarySearchTree.h"
#include <iostream>
#include <string>
using namespace std;
BinarySearchTree::BinarySearchTree()
{
	root = new Node;
	root->contexts = nullptr;
	root->right = nullptr;
	root->left = nullptr;
}

BinarySearchTree::~BinarySearchTree()
{
	Flush();

	root = NULL;
	delete root;
}

bool BinarySearchTree::Insert(string stringKey, string beforeCon, string afterCon)
{
	if (isEmpty()) {
		root->key = stringKey;
		LinkedList* l = new LinkedList;
		l->setKey(stringKey);
		root->contexts = l;
		root->contexts->insert(beforeCon, afterCon);
		return true;
	}
	else
	{
		Node* nNode = new Node;
		nNode->key = stringKey;
		Node* curr = root;
		Node* parent = nullptr;

		// traverse the tree and find parent node of key
		while (curr != nullptr)
		{
			// update parent node as current node
			parent = curr;

			// if given key is equal to the current node, the node exists. add context to linked list
			if (stringKey == curr->key) {
				curr->contexts->insert(beforeCon, afterCon);				
				nNode = NULL;
				delete nNode;
				return true;
			}
			else if (stringKey < curr->key) { // go left 
				curr = curr->left;
			}
			else // go right
			{
				curr = curr->right;
			}
		}

		// assign nNode to appropirate parent pointer
  		if (stringKey < parent->key) {
			LinkedList* l = new LinkedList;
			l->setKey(stringKey);
			nNode->contexts = l;
			nNode->contexts->insert(beforeCon, afterCon);
			
			parent->left = nNode;
		}
		else
		{
			LinkedList* l = new LinkedList;
			l->setKey(stringKey);
			nNode->contexts = l;
			nNode->contexts->insert(beforeCon, afterCon);

			parent->right = nNode;
		}
	}
	return true;
}


void BinarySearchTree::Display()
{
	Display(root); // runs Display recursive function
}

void BinarySearchTree::Display(Node* curr)
{
	if (root != nullptr)
	{
		if (curr->left != nullptr)
		{
			Display(curr->left);
		}
		// set getMaxBeforeSize() for each context in contexts (need to have function in LinkedList
		curr->contexts->setMaxBeforeSize(getMaxBeforeSize());
		curr->contexts->printList();

		if (curr->right != NULL)
		{
			Display(curr->right);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
}

int BinarySearchTree::getMaxBeforeSize() // returns max before size
{
	int max = 0;
	//cout << "overall getMaxBeforeSize(root) = " << getMaxBeforeSize(root, max) << endl;
	return getMaxBeforeSize(root, max);
}

int BinarySearchTree::getMaxBeforeSize(Node* curr, int& max)
{
	//int max = 0;
	if (root != nullptr)
	{
		if (curr->left != nullptr)
		{
			getMaxBeforeSize(curr->left, max);
		}

		int thisMax = curr->contexts->getMaxBeforeSize();
		if (thisMax > max)
		{
			max = thisMax;
		}

		if (curr->right != NULL)
		{
			getMaxBeforeSize(curr->right, max);
		}
	}
	else
	{
		cout << "The tree is empty" << endl;
	}
	return max;
}

void BinarySearchTree::Flush()
{
	Flush(root);
}

void BinarySearchTree::Flush(Node* curr)
{
	if (curr == nullptr) return;

	Flush(curr->left);
	Flush(curr->right);

	curr->contexts = NULL; // delete linked list
	delete curr->contexts;

	curr = NULL; // delete nodes
	delete curr;
}

bool BinarySearchTree::isEmpty() const
{
	return root->contexts == nullptr;
}

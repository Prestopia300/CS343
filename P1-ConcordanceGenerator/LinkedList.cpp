#include "LinkedList.h"

LinkedList::LinkedList()
{
	head = new Node;
	head = nullptr;
}

LinkedList::~LinkedList()
{
	cout << "in ~LinkedList" << endl;
	clear();
}

void LinkedList::insert(string before, string after)
{
	Context* context = new Context;
	context->setBefore(before);
	context->setKeyword(key);
	context->setAfter(after);

	Node* temp = new Node;
	temp->data = context;
	
	if (head == nullptr) // head should be: nullptr. but can't do this check. head doesn't exist. but i
	{
		head = temp;
		tail = temp;
		temp = NULL;
		delete temp; 
	}
	else
	{
		tail->next = temp;
		tail = temp;
	}
}

void LinkedList::clear()
{
	Node* iterator = head;

	while (iterator != nullptr)
	{
		head = iterator->next;
		
		delete iterator->data; // delete context
		iterator->data = NULL;

		delete iterator; // delete node
		iterator = NULL;
		iterator = head;
	}
	delete head; 
	head = nullptr;
}

void LinkedList::printList()
{
	Node* temp = new Node;
	temp = head;
	while (temp != nullptr)
	{
		
		temp->data->printContext();
		temp = temp->next;
	}
	temp = NULL;
	delete temp;
	
}

int LinkedList::getMaxBeforeSize() //returns max size of the context(s)
{
	Node* temp = new Node;
	temp = head;
	int max = 0;
	while (temp != nullptr) // check each data for before, and update max
	{
		int tempMax = temp->data->getBefore().size();
		if (tempMax > max)
		{
			max = tempMax;
		}
		temp = temp->next;
	}
	temp = NULL;
	delete temp;
	
	return max;
}

void LinkedList::setMaxBeforeSize(int max) // updates maxBeforeSize for each context in the LinkedList
{
	Node* temp = new Node;
	temp = head;
	while (temp != nullptr) 
	{
		temp->data->setMaxBeforeTextSize(max);
		temp = temp->next;
	}
	temp = NULL;
	delete temp;
	
}

void LinkedList::setKey(string keyString)
{
	key = keyString;
}

string LinkedList::getKey()
{
	return key;
}
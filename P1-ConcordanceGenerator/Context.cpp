#include "Context.h"

Context::Context()
{
}

string Context::getBefore()
{
	return beforeText;
}

string Context::getKeyword()
{
	return keywordText;
}

string Context::getAfter()
{
	return afterText;
}

int Context::getMaxBeforeTextSize()
{
	return maxBeforeTextSize;
}

void Context::setBefore(string before)
{
	beforeText = before;
}

void Context::setKeyword(string key)
{
	keywordText = key;
}

void Context::setAfter(string after)
{
	afterText = after;
}

void Context::setMaxBeforeTextSize(int beforeSize)
{
	maxBeforeTextSize = beforeSize;
}

void Context::printContext() const
{
	cout << setw(maxBeforeTextSize) << right << beforeText << "|" << keywordText << "| " << setw(4) << afterText << endl;
}

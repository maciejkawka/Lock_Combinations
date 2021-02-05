#pragma once

#include"dictionary.h"

using namespace std;

class Lock {
public:

	Lock(string path);
	~Lock();

	void FindCombinations();
	void FindInDictionary(const string& word);

	set <string>& GetFound() { return d->foundwords; }
protected:

	void Combinations(string temp, int i);
	

	int wheelNumber;
	int letterOnWheel;
	char** wheels;
	Dictionary* d;
	set<string> foundLetter;
	set<string> allCombinations;

};
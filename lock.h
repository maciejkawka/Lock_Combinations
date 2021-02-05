#pragma once

#include"dictionary.h"

using namespace std;

class Lock {
public:

	Lock(string path, string dictionaryPath);
	Lock() : wheels(nullptr), d(nullptr) {}
	~Lock();

	void FindCombinations();

	inline const set<string>& GetFound() const { return d->GetFoundWords(); }

protected:

	void Combinations(string temp, int i);

	int wheelNumber;
	int letterOnWheel;
	char** wheels;  //Holds wheels letters
	Dictionary* d;


};
#pragma once
#include<iostream>
#include<fstream>
#include<string>
#include<set>
#include<vector>
#include<algorithm>

using namespace std;


class Dictionary{
public:

	Dictionary(string path, int maxLength);

	Dictionary(): words(nullptr), maxWordLength(0) {}

	~Dictionary() { delete words; }

	void FindWord(const string& word);

	inline const set<string>& GetFoundWords() const { return foundwords; }
	inline bool isDictionaryCreated() { return words != nullptr; }

protected:
	vector<vector<string>>::iterator it;
	vector<vector<string>>* words;
	set<string> foundwords;
	int maxWordLength;
};
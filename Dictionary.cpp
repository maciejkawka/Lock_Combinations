#include"dictionary.h"

Dictionary::Dictionary(string path, int maxLength)
{
	/*This opens a file containing dictionary words. Words are sorted and placed in a unique vector according to the first letter. 
	This increases performance during searching words in the combination. After writing every word from the dictionary every vector 
	is sorting according to the string size. This also increases searching performance words in the combination. I have chosen vector 
	container because it has the best iteration performance.*/
	ifstream file;
	file.open(path, ios::in);
	if (file.good())
	{
		maxWordLength = maxLength;
		words = new vector<vector<string>>(26);
		it = words->begin();

		string buffor;		
		while (getline(file, buffor))
		{
			if (buffor.size() > maxWordLength)
				continue;

			string bufforCapital = "";
			for (auto s : buffor)
				bufforCapital += s - 32;

			(*(it + ((int)bufforCapital[0] - 65))).emplace_back(bufforCapital);
		}

		for (it = words->begin(); it != words->end(); it++)
		{
			sort((*it).begin(), (*it).end(), [](const string& s1, const string& s2)->bool {
				return s1.size() < s2.size();
				});
		}
	}
	else
	{
		cout << "File " << path << " not found or corrupted!!" << endl;
		words = nullptr;
		maxWordLength = 0;
	}
}

/*This finds all words in the combination. Firstly it removes potentially space in the first string's positions.
And sets iterator to correct vector.The function searches words only with the same first letter as the combination's 
first letter. This prevents from searching the same combinations multiple times. 

Before the main iteration loop I set local variables, this increases performance because the program has quick access
to these variables. Also setting ++j instead of j++ increase performance.

After finding the word in the combination the word is inserted in the set container.*/
void Dictionary::FindWord(const string& word)
{
	int spaceConuter = 0;
	for (auto s : word)
	{
		if (s != ' ')
		{
			it = words->begin() + ((int)s - 65);
			break;
		}
		spaceConuter++;
	}

	const char* wordC_string = word.c_str();
	int wordSize = word.size() - spaceConuter;
	vector<string>::iterator itEnd = (*it).end();

	for (vector<string>::iterator j = (*it).begin(); j != itEnd; ++j)
	{
		if (wordSize < (*j).size())
			break;
		if (strstr(wordC_string, (*j).c_str()) == NULL)
			continue;
		foundwords.insert(*j);
	}
}
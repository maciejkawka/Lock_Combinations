#include "lock.h"

Lock::Lock(string path)
{

	ifstream file;
	file.open(path, ios::in);
	if (file.good())
	{
		file >> wheelNumber;
		file >> letterOnWheel;

		wheels = new char* [wheelNumber];
		for (int i = 0; i < wheelNumber; i++)
			wheels[i] = new char[letterOnWheel];

		string buffor;
		for (int i = 0; i < wheelNumber; i++)
		{
			file >> buffor;
			for (int j = 0; j < letterOnWheel; j++)
				wheels[i][j] = buffor[j];
		}
	}
	else
	{
		wheels = nullptr;
		cout << "File "<< path<<" not found or corrupted!!" << endl;
	}

	d = new Dictionary("dictionary.txt", wheelNumber);
}

Lock::~Lock()
{
	for (int i = 0; i < letterOnWheel; i++)
		delete[] wheels[i];
	delete[] wheels;
}

void Lock::FindCombinations()
{
	if (wheels == nullptr||d==nullptr)
		return;
	if (!(wheelNumber && letterOnWheel))
		return;
	if (!d->isDictionaryCreated())
		return;

	Combinations(string(wheelNumber, ' '), wheelNumber - 1);
}

void Lock::Combinations(string temp, int i)
{
	if (i < 0)
		return;

	for (int j = 0; j < letterOnWheel; j++)
	{
		temp[i] = wheels[i][j];
		Combinations(temp, i - 1);
		d->FindWord(temp);
	}
}





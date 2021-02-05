#include "lock.h"

Lock::Lock(string path, string dictionaryPath)
{
	
	/*This code reads wheels numberand letter per wheel number, then writes letters to wheels array.
	I used the 2D array to hold wheels letter because referencing to each component is quick and clear in code*/
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

	d = new Dictionary(dictionaryPath, wheelNumber);
}

Lock::~Lock()
{
	for (int i = 0; i < letterOnWheel; i++)
		delete[] wheels[i];
	delete[] wheels;
}

void Lock::FindCombinations()
{
	//Checks if combination calculation can be processed.
	if (wheels == nullptr||d==nullptr)
		return;
	if (!(wheelNumber && letterOnWheel))
		return;
	if (!d->isDictionaryCreated())
		return;

	Combinations(string(wheelNumber, ' '), wheelNumber - 1);
}

/*This finds all k^ n combinations recursively(k – number of wheels, n – letters on the wheel).
Combinations are not stored because the array would be hugeand that increases RAM usage.
Additionally every writes decreases algorithm performance.Words in the combination are found in runtime.
This algorithm should not cause stack overflow because the recursive does not go very deep(only k + 1)
The algorithm is optimized according to a single thread.Which in my opinion is enough for this kind of operation.
Multithread is not necessary.*/
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





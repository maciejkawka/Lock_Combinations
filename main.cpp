#include"dictionary.h"
#include"lock.h"

#include<chrono>

int main()
{
	//Dictionary d("dictionary.txt", 5);
	//d.FindWord("wadog");
	int i = 0;
	Lock l("wheels.txt");
	float timer = 0;



	int iteraions = 1;
	while (i < iteraions)
	{
		auto start = chrono::high_resolution_clock::now();
		l.FindCombinations();
		auto stop = chrono::high_resolution_clock::now();
		timer += std::chrono::duration_cast<std::chrono::microseconds>(stop - start).count();
		i++;
	}

	for (auto s : l.GetFound())
		cout << s << endl;
	cout << l.GetFound().size() << endl;
	cout << timer/ iteraions << " us" << endl;
	system("pause");



	return 0;
}
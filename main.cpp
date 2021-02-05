#include"dictionary.h"
#include"lock.h"

#include<chrono>

int main(int argc,char* argv[])
{
	string wheelPath = "";
	string dictionaryPath = "";
	if (argc >= 3)
	{
		wheelPath = argv[1];
		dictionaryPath = argv[2];
	}
	else
	{
		cout << "Wheel and dictionary path wasn't passed as parameter!" << endl;
		system("pause");
		return 0;
	}
	
	Lock l(wheelPath, dictionaryPath);
	

	float timer = 0;
	int i = 0;
	int iteraions = 100000;
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
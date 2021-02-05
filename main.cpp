#pragma once
#include"dictionary.h"
#include"lock.h"



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
	l.FindCombinations();
		
	for (auto s : l.GetFound())
		cout << s << endl;
	cout << "Found "<< l.GetFound().size() << " words" <<endl;
	system("pause");

	return 0;
}
#include <iostream>
#include "Anketa.h"
using namespace std;

int main(int argc, char *args[])
{	
	bool is_adm = false;
	for (int i = 0; i < argc; i++)
	{
		if (string(args[i]) == "admin") is_adm = true;
	}

	if (is_adm)
	{
		cout << "\n Admin!!!!!!!";
	}



	Anketa ank;
	if (ank.Load("c:\\1\\a.txt"))
	{
		ank.Qwester();
		cout << ank;
	}
	
	ofstream file;
	file.open("c:\\1\\11.txt");
	if (file.is_open())
	{
		file << ank;
		file.close();
	}
	else
	{
		cout << "Can not open file c:\\1\\11.txt";
	}
}

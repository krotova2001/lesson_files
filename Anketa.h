#pragma once
#include "Punkt.h"
#include <fstream>//структура файла
class Anketa
{
	int Count;
	Punkt* qwests;
	string FIO;
public:
	Anketa():Count {0}, qwests{nullptr}, FIO{"Anonim"}{}
	~Anketa()
	{
		if (qwests)
		{
			delete[] qwests;
		}
	}
	void Qwester()
	{
		cout << "\nStarting filling Anket: ";
		for (int i = 0; i < Count; i++)
		{
			qwests[i].InputAnswer(i);
		}
		cout << "\nThe End!!!";
	}
	bool Load(string filename)
	{
		ifstream file;
		file.open(filename);
		if (file.is_open())
		{
			Punkt t;
			Count = 0;
			while (!file.eof())
			{
				file >> t;
				Count++;
			}
			if (qwests)
				delete[]qwests;
			qwests = new Punkt[Count];
			file.seekg(0, ios::beg);
			for (int i = 0; i < Count; i++)
			{
				file >> qwests[i];
			}
			file.close();
			return true;
		}
		else
		{
			cout << "Can not open file " << filename;
			return false;
		}
	}
	friend ostream& operator<<(ostream&o, const Anketa& a)
		{
			o << "\n----------------------------------";
			o << "\n				Anketa				";
			o << "\n FIO" << a.FIO;
			for (int i = 0; i< a.Count; i++)
				o << a.qwests[i];
			o << "\n--------------------------------------";
			return o;
		}

}; 


#pragma once
#include <iostream>
#include <string>
using namespace std;

class Punkt
{
	string Qwest;
	string Answer;
public:
	Punkt(){}
	Punkt(string q, string a ):Qwest{q}, Answer{a}{}
	Punkt(string q): Punkt(q, ""){}
	bool Empty() { return Answer.empty(); }
	friend ostream& operator <<(ostream& o, const Punkt& p)
	{
		o << "\nQuest: " << p.Qwest;
		o << "\nAnswer: " << p.Answer;
		return o;
	}
	friend istream& operator>>(istream& i, Punkt& p)
	{
		getline(i, p.Qwest);
		p.Answer = "";
		return i;
	}
	void InputAnswer(int num=-1)
	{
		cout << "\n";
		if (++num)
		{
			cout << num<<".";
		}
		cout << Qwest;
		cout << "\nInput your answer: ";
		getline(cin, Answer);
	}

};


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class CheckS
{
	string text;
	int howManyTimesOpen;
	int howManyTimesClosed;
public:
	CheckS(): howManyTimesOpen(0), howManyTimesClosed(0) {};
	CheckS(string someTextFromFile)
	{
		howManyTimesOpen = 0;
		howManyTimesClosed = 0;
		text = someTextFromFile;
		
		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == '(')
				howManyTimesOpen++;
			if (text[i] == ')')
				howManyTimesClosed++;
		}
	}

	void insertSomeString(string someTextFromFile)
	{
		howManyTimesOpen = 0;
		howManyTimesClosed = 0;
		text = someTextFromFile;

		for (int i = 0; i < text.size(); i++)
		{
			if (text[i] == '(')
				howManyTimesOpen++;
			if (text[i] == ')')
				howManyTimesClosed++;
		}
	}

	void showResult()
	{
		if (howManyTimesOpen > howManyTimesClosed)
			cout << "Formula is incorrect. Brackets are opened " << howManyTimesOpen - howManyTimesClosed << " times more than needed." << endl;
		if (howManyTimesOpen < howManyTimesClosed)
			cout << "Formula is incorrect. Brackets are closed " << howManyTimesClosed - howManyTimesOpen << " times more than needed." << endl;
		if (howManyTimesOpen == howManyTimesClosed)
			cout << "Formula is correct." << endl;
	}
};


int main() {
	CheckS test;
	string str;

	ifstream file("F:\\FromVisual\\OOP 3\\three_expressions.txt");
	if (file.is_open())
	{
		while (getline(file, str)) {
			cout << str << endl;
			test.insertSomeString(str);
			test.showResult();
		}
	}

	file.close();
	system("pause");

	return 0;
}
#include "Answer4.h"

Answer4::Answer4()
{
}

Answer4::~Answer4()
{
}

Answer4::Answer4(const vector<string>& Answer)
{

}

int Case(int a, int b, int c)
{
	int result = 0;

	if (a == b == c) 
	{
		result=(a * 1000) + (5000);
	}

	if ((a == b) || (a == c) || (b == c))
	{
		result = a == b ? a : c;
	}

	if (a != b != c)
	{
		result = a >= b ? a : b;

		result = result >= c ? result : c;
	}

	return result;
}

// 48 ~ 57;
vector<string> Answer4::TEST()
{	
	int Number = 0;
	cin >> Number;
	cin.clear();

	for (int i = 0; i <= Number; ++i)
	{
		string Temp;

		Temp.reserve(6);
		Temp.clear();

		Temp= InputGetLine<string>();

		AnswerTEST.push_back(Temp);
	}

	int max = 0;

	//for (const auto&elem : AnswerTEST)
	//{
	//	if (elem.size() == 0) { continue; }
	//	cout << elem << endl;
	//	cout << elem.size() << endl;
	//}

	for (const auto&elem : AnswerTEST)
	{
		if (elem.size() == 0) { continue; }

		int temp=Case(((int)elem[0]-48), 
		((int)elem[2]-48),((int)elem[4]-48));

		max = max >= temp ? max : temp;
	}


	vector<string> result;

	result.push_back(to_string(max));

	return result;
}



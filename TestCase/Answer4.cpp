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

	if (a == b && a == c)
	{
		result = ((a * 1000) + 5000);
	}

	else if ((a == b) || (a == c) || (b == c))
	{
		if (a == b) { result = a; }
		if (a == c) { result = c; }
		if (c == b) { result = c; }
		result *= 500;
		result += 2000;
	}
	else if (a != b != c)
	{
		result = a >= b ? a : b;

		result = result >= c ? result : c;

		result *= 200;
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

		Temp = InputGetLine<string>();

		AnswerTEST.push_back(Temp);
	}

	int max = 0;

	//for (const auto&elem : AnswerTEST)
	//{
	//	if (elem.size() == 0) { continue; }
	//	cout << elem << endl;
	//	cout << elem.size() << endl;
	//}

	//for (const auto&elem : AnswerTEST)
	//{
	//	if (elem.size() == 0) { continue; }

	//	cout << ((int)elem[0] - 48)<<endl;
	//	cout << ((int)elem[2] - 48)<<endl;
	//	cout << ((int)elem[4] - 48)<<endl;
	//}
	//cout << "==========================" << endl;
	//cout << Case(6,3,6) << endl;
	//cout << Case(4,4,4) << endl;
	//cout << Case(6,2,5) << endl;
	//cout << "==========================" << endl;
	//

	for (const auto&elem : AnswerTEST)
	{
		if (elem.size() == 0) { continue; }

		int temp = Case(((int)elem[0] - 48),
			((int)elem[2] - 48), ((int)elem[4] - 48));

		max = max >= temp ? max : temp;
	}


	vector<string> result;

	result.push_back(to_string(max));

	return result;
}



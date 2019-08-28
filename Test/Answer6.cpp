#include "Answer6.h"

Answer6::Answer6()
{
}

Answer6::~Answer6()
{
}

Answer6::Answer6(const vector<string>& Answer)
{

}

vector<string> Answer6::TEST()
{	// За height ї­ width

	int height = 0;

	cin >> height;

	int max = 0;

	int X = 1;
	int Y = 1;

	for (int i = 0; i <= height; ++i)
	{
		AnswerTEST.push_back(InputGetLine<string>());
	}

	for (const auto&elem : AnswerTEST)
	{
		cout << elem << endl;
	}

	int Index = 0;
	int resultX = 0;
	int resultY = 0;

	for (auto&elem : AnswerTEST)
	{	
		for (int i = 1; i<=height; ++i)
		{
			int temp = 0;
		
			/*temp += to_string(elem[Index]) * 10;
			temp += elem[Index+1];*/
			
			if (temp >= max)
			{
				max = temp;
				resultX = X;
				resultY = Y;
			}
			Index += 2;
			++X;
		}
		++Y;
	}
	cout << " x  y   max " << endl;
	cout << resultX << endl;
	cout << resultY << endl;
	cout << max << endl;
	return vector<string>();
}



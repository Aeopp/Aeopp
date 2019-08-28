#include "Answer1.h"

Answer1::Answer1()
{
}

Answer1::~Answer1()
{
}

Answer1::Answer1(const vector<string>& Answer)
{
	
}

const size_t Pow(const size_t TargetNumber)
{
	return TargetNumber * TargetNumber;
}

vector<string> Answer1::operator()()
{
	vector<string> TEST;

	int studentNumber = 5;

	for (int i = 1; i <= studentNumber; ++i)
	{
		TEST.push_back(Input<string>());
	}

	assert(TEST.size() == 5 && "입력 오류");

	size_t result = 0;

	for (const auto&elem : TEST)
	{
		result+=Pow(atoi(elem.c_str()));
	}

	vector<string>a;

	a.push_back(to_string(result%10));

	return a;
}



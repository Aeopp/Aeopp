#include "pch.h"
#include <vector>
#include <string>
#include "Answer1.h"
#include "Answer4.h"
#include "Answer6.h"

int main()
{
	// 문제2번
	vector<string> TEMP;

	auto result = Answer1(TEMP).operator()();

	for (const auto&elem : result)
	{
		cout << elem;
	}

	//vector<string> TEMP2;

	//Answer6 Answer6TEST(TEMP2);

	//Answer6TEST.TEST();

	//vector<string> TEMP3;

	//Answer4 Answer4TEST(TEMP3);

	//auto result = Answer4TEST.TEST();

	//for (const auto&elem : result)
	//{
	//	cout << elem;
	//}

	return 0;
}
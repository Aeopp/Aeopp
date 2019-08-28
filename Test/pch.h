#pragma once
#include <iostream>
#include <string>
#include <limits>
#include <vector>
#include <assert.h>
using namespace std;


template<typename T>
T InputGetLine()
{
	T val;

	getline(cin, val);
	cin.clear();
	//val = cin.get(); 

	//while (true)
	//{
	///*	char temp;

	//	while (1)
	//	{
	//		cin >> temp;
	//		if (temp == 13) { break; }
	//		val.push_back(temp);
	//	}*/
	//	

	//	if (cin.fail())
	//	{
	//		cin.clear();
	//		cin.ignore(INT_MAX, '\n');

	//		cout << typeid(T).name() << " : 입력 에러" << endl;
	//	}

	//	else { break; }
	//}
	//cin.ignore(INT_MAX,'\n');
	return val;
}

template<typename T>
T Input()
{
	T val;

	cin >> val;
	cin.clear();
	//val = cin.get(); 

	//while (true)
	//{
	///*	char temp;

	//	while (1)
	//	{
	//		cin >> temp;
	//		if (temp == 13) { break; }
	//		val.push_back(temp);
	//	}*/
	//	

	//	if (cin.fail())
	//	{
	//		cin.clear();
	//		cin.ignore(INT_MAX, '\n');

	//		cout << typeid(T).name() << " : 입력 에러" << endl;
	//	}

	//	else { break; }
	//}
	//cin.ignore(INT_MAX,'\n');
	return val;
}



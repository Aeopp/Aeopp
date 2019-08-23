#include "pch.h"
#include <iostream>
#include <functional>
#include <cassert>
#include <string>
#include <cmath>
using namespace std;

// KaKao N Game by ÀÌÈ£ÁØ

string A(int Target, size_t P)
{
	string result;

	string Table{ "0123456789ABCDEF" };

	if (!Target) { return string{ '0' }; }

	for (;Target > 0;)
	{
		result.push_back(Table[Target%P]);
		Target /= P;
	}
	std::reverse(result.begin(), result.end());
	return result;
}

int main()
{
	size_t n, t, m, p;
	cin >> n >> t >> m >> p;

	string temp;

	for (int i = 0; i < t*m; ++i)
	{
		temp+=A(i, n);
	}

	string result;
	for (int i = p-1,count=0;count<t;count++,i+=m)
	{
		result.push_back(temp[i]);
	}
	cout << result;
}

#pragma once

#include <vector>
#include <string>

class ITest
{
public:
	ITest(const std::vector<std::string>&) {}
	ITest() {};
	virtual void Test() = 0;
};

class Test01 : ITest
{
public:
	Test01(const std::vector<std::string>& a_arrString);
	~Test01();

	virtual void Test() override;
};
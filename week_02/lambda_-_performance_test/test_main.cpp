/*
	lambda expression
		https://docs.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019
		https://lunapiece.net/Article/27419
*/

#include <iostream>
#include <functional>		// std::bind
#include <vector>
#include <random>
#include <windows.h>


const int TEST_LOOP_COUNT = 100000000;
//const int TEST_LOOP_COUNT = 10000000;

__int64 g_NumberSum;

void GetSumFunction(int Num)
{
	g_NumberSum = g_NumberSum + Num;
}
 
struct GetSumFunctor
{
	void operator()(int Num)
	{
		g_NumberSum = g_NumberSum + Num;
	}
};


int main()
{
	std::mt19937_64 RandomEngine;
	std::uniform_int <> RandomRange(0, INT32_MAX);
	RandomEngine.seed(GetTickCount());
 
	std::vector<int> RandumNumbers;
	RandumNumbers.reserve(TEST_LOOP_COUNT);
	for (int i = 0; i < TEST_LOOP_COUNT; ++i)
	{
		RandumNumbers.push_back(RandomRange(RandomEngine));
	}
 
	DWORD Tick;

	{	// global function
		g_NumberSum = 0;
		Tick = GetTickCount();
		for_each(RandumNumbers.begin(), RandumNumbers.end(), GetSumFunction);
		printf("Global Function :: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	{	// C++11 std::bind
		g_NumberSum = 0;
		std::function<void(int)> FunctionObject = std::bind(&GetSumFunction, std::placeholders::_1);
		Tick = GetTickCount();
		for_each(RandumNumbers.begin(), RandumNumbers.end(), FunctionObject);
		printf("Bind Function   :: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	{	// functor
		g_NumberSum = 0;
		Tick = GetTickCount();
		for_each(RandumNumbers.begin(), RandumNumbers.end(), GetSumFunctor());
		printf("Functor         :: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	{	// C++11 Lambda
		g_NumberSum = 0;
		Tick = GetTickCount();
		for_each(RandumNumbers.begin(), RandumNumbers.end(), 
			[](int Num)
			{
				g_NumberSum = g_NumberSum + Num;
			}
		);
		printf("C++11 Lambda    :: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	{ // C++11 Bind Lambda
		g_NumberSum = 0;
		Tick = GetTickCount();
		std::function<void(int)> BindLambda =
			[](int Num)
			{
				g_NumberSum = g_NumberSum + Num;
			};
		for_each(RandumNumbers.begin(), RandumNumbers.end(), BindLambda);
		printf("Bind Lambda     :: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	{ // C++11 Auto bind Lambda
		g_NumberSum = 0;
		Tick = GetTickCount();
		auto AutoBindLambda = 
			[](int Num)
			{
				g_NumberSum = g_NumberSum + Num;
			};
		for_each(RandumNumbers.begin(), RandumNumbers.end(), AutoBindLambda);
		printf("Auto Bind Lambda:: Sum : %I64d, Time : %dms\n", g_NumberSum, GetTickCount() - Tick);
	}

	return 0;
}

/*
	lambda expression
		https://docs.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-in-cpp?view=vs-2019
*/

#include <iostream>
#include <functional>		// std::bind
#include <string>


int Test0(int val1, int val2, const std::string& text)
{
	std::cout << text << std::endl;

	return (val1 + val2);
}


int main()
{
	{	// C++11 : std::bind
		auto aFunc = std::bind(Test0, std::placeholders::_1, std::placeholders::_2, "hello");
		std::cout << aFunc(10, 20) << std::endl;
	}
	
	{	// C++11 : lambda expression
		auto aVal = 30;

		auto aFunc = [&](int val1, int val2)
//		auto aFunc = [&](int val1, int val2)->int
			{
				return (Test0(val1, val2 + aVal, "world"));
			};
		std::cout << aFunc(20, 30) << std::endl;
	}	

	return 0;
}

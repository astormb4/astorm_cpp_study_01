/*
	auto - retun type deduction
		https://oopscenities.net/2018/03/04/auto-return-type-deduction/
*/

#include <iostream>


auto Test0(int a, int b) -> decltype(a + b)		// C++11
{
	return (a + b);
}

auto Test1(int a, int b)	// C++14
{
	return (a + b);
}

template <typename T>
auto Test2(T a, T b)		// C++14
{
	return (a + b);
}

/*
auto Test3(auto a, auto b)	// error	// C3533: 매개 변수에 'auto'이(가) 포함된 형식을 포함할 수 없습니다.
{
	return (a + b);
}
*/


int main()
{
	std::cout << "test 0 : " << Test0(100, 50) << std::endl;
	std::cout << "test 1 : " << Test1(100, 50) << std::endl;
	std::cout << "test 2 : " << Test2(100, 50) << std::endl;

	return 0;
}

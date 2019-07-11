/*
	constexpr
		https://en.cppreference.com/w/cpp/language/constexpr
*/

#include <iostream>


const double g_Val0(9.8);			// Old

constexpr double g_Val1(9.8);		// C++11

constexpr int g_Val2 = (120 + static_cast<int>(g_Val1));	// C++11

constexpr int Test0(int x, int y)	// C++11
{
/*  // error
    auto n1 = 2;    // 지역 변수 사용 X
    auto n2 = 3;    // 지역 변수 사용 X
    auto value = ((x*y) * n1) + ((x*y) * n2);    // 지역 변수 사용 X
    return value;    // 함수 본체 는 return 문으로만 (?) 구성되어야 함
*/

    return ((x*y) * 2) + ((x*y) * 3);
}

constexpr int Test1(int x, int y)	// C++14
{
    if ((x + y) == 30)
    {
        return x * 2;
    }

    return x * 3;
}


int main()
{
	std::cout << "g_Val1 : " << g_Val1 << std::endl;			// OK
	std::cout << "g_Val2 : " << g_Val2 << std::endl;			// OK
	std::cout << "test 0 : " << Test0(10, 20) << std::endl;		// OK
	std::cout << "test 1 : " << Test1(10, 20) << std::endl;		// OK

	return 0;
}

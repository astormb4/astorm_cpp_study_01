/*
	structured bindings (structured binding declaration)
		https://en.cppreference.com/w/cpp/language/structured_binding
*/

#include <iostream>
#include <tuple>
#include <string>


std::tuple<int, std::string, float> Test0()
{
	return std::make_tuple(15, "hello", 1237.f);
}

auto Test1()
{
//	return { 15, "hello", 1237.f };	// error C3108: 이니셜라이저 목록이 식이 아니므로 형식을 추론할 수 없습니다.	// error C2440: 'return': 'initializer list'에서 'auto'(으)로 변환할 수 없습니다.
	return std::make_tuple(15, "hello", 1237.f);
}


int main()
{
	{	// Old
		std::tuple<int, std::string, float> aVal = Test0();

		std::cout << "test-0 : " << std::get<0>(aVal) << ", " << std::get<1>(aVal) << ", " << std::get<2>(aVal) << std::endl;
	}

	{	// C++17
		auto[a, b, c] = Test1();			// structured bindings (structured binding declaration)		// https://en.cppreference.com/w/cpp/language/structured_binding
//		const auto[a, b, c] = Test1();		// OK

		std::cout << "test-1 : " << a << ", " << b << ", " << c << std::endl;
	}

	return 0;
}

/*
	constexpr lambda
		https://docs.microsoft.com/ko-kr/cpp/cpp/lambda-expressions-constexpr?view=vs-2019
		https://github.com/MicrosoftDocs/cpp-docs/blob/master/docs/cpp/lambda-expressions-constexpr.md
		https://isocpp.org/files/papers/N4487.pdf
*/

#include <iostream>


template<int VVAL>
class Test1
{
public:
	enum {
		value = VVAL,
	};
};


int main()
{
	{	// case 1
		constexpr auto func_add = [](int x, int y)
		{
			return x + y;
		};

		static_assert(Test1<func_add(10, 20)>::value == 30, "case 1 : error : 30");		// OK
// 		static_assert(Test1<func_add(10, 20)>::value == 31, "case 1 : error : 31");		// error
// 		static_assert(Test1<func_add(10, 20)>::value == 50, "case 1 : error : 50");		// error
	}

	{	// case 2
		static_assert(Test1 < ([](int x, int y) { return x + y; }) (10, 20) > ::value == 30, "case 2 : error : 30");		// OK
// 		static_assert(Test1 < ([](int x, int y) { return x + y; }) (10, 20) > ::value == 31, "case 2 : error : 31");		// error
// 		static_assert(Test1 < ([](int x, int y) { return x + y; }) (10, 20) > ::value == 50, "case 2 : error : 50");		// error
	}

	{	// case 3
		constexpr auto func_check = [](int x, int y)
		{
			if (((x + y) % 2) == 0)		// 람다식에 비교 구문이 포함되어도 상수 구문 (constexpr) 으로 지정 가능
			{
				return true;
			}

			return false;

//			return (((x + y) % 2) == 0);
		};

		static_assert(Test1<func_check(10, 20)>::value == true, "case 3 : error : 1");		// OK
//		static_assert(Test1<func_check(10, 20)>::value == false, "case 3 : error : 2");		// error
	}

	return 0;
}

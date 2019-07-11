/*
	optional
		https://en.cppreference.com/w/cpp/utility/optional
		http://occamsrazr.net/tt/317
*/

#include <optional>
#include <iostream>


std::optional<int> Test1(int a, int b)
{
	std::optional<int> aRet;

	if ((a % 2) == 0)
	{
		aRet = a + b;
	}

	return aRet;
}

struct Test2
{
public:
	std::optional<int> m_Val1;
};


int main()
{
	{	// 함수 반환값 검사
//		auto aRet = Test1(100, 50);		// OK		// 있음
		auto aRet = Test1(101, 50);		// OK		// 없음
		if (aRet)
		{
			std::cout << "test 1 : " << (*aRet) << std::endl;
		}
		else
		{
			std::cout << "test 1 : none" << std::endl;
//			std::cout << "test 1 : " << (*aRet) << std::endl;	// OK	// 해당 형식의 기본값이 지정되어 반환됨 (→ 에러 처리되거나 예외 (exception) 를 throw 하는 것이 아님에 유의)
		}
	}

	{	// 객체 값 지정 여부 검사
		Test2 aTest2;
		if (aTest2.m_Val1)
		{
			std::cout << "test 2 : " << (*aTest2.m_Val1) << std::endl;
		}
		else
		{
			std::cout << "test 2 : none" << std::endl;
		}

		aTest2.m_Val1 = 1236;
		if (aTest2.m_Val1)
		{
			std::cout << "test 2 : " << (*aTest2.m_Val1) << std::endl;
		}
		else
		{
			std::cout << "test 2 : none" << std::endl;
		}

	}

	return 0;
}

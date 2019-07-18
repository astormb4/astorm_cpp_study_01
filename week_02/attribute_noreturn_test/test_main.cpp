/*
	attribute : noreturn
		https://en.cppreference.com/w/cpp/language/attributes/noreturn
		https://riptutorial.com/ko/cplusplus/example/18670/--noreturn--
*/

#include <iostream>
#include <string>


__declspec(noreturn)	// C++03 / Microsoft Specific
void Test0(const std::string& text, int val)
{
	std::cout << "test 1 : " << text << std::endl;

	if (val < 0)
	{
		throw std::bad_alloc();
	}

	std::terminate();
}

[[noreturn]]			// C++11
void Test1(const std::string& text, int val)
//int Test1(const std::string& text, int val)				// warning		// C4646: 'noreturn'으로 선언된 함수에 void가 아닌 반환 형식이 있습니다.
{
	std::cout << "test 1 : " << text << std::endl;

	if (val < 0)
	{
		throw std::bad_alloc();
	}

	std::terminate();
}

[[noreturn]]
int Test2(int val1, int val2)		// warning		// C4646: 'noreturn'으로 선언된 함수에 void가 아닌 반환 형식이 있습니다.		// C4645: 'noreturn'으로 선언된 함수에 return 문이 있습니다.
{
	return (val1 + val2);
}


int main()
{
//	Test0("hello", 1);

	Test1("hello", 1);

//	Test2(20, 30);

	return 0;
}

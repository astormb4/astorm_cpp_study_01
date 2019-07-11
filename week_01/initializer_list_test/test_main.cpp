/*
	initializer_list
		https://en.cppreference.com/w/cpp/utility/initializer_list
		http://egloos.zum.com/sweeper/v/3058167
		https://narss.tistory.com/entry/5%EC%9D%BC%EC%B0%A8-initializerlist
*/

#include <initializer_list>
#include <iostream>
#include <stdarg.h>		// va_arg, va_start, va_end
#include <vector>


int Test0(int count, ...)
{
  int aRet = 0;
  va_list aList;
 
  va_start(aList, count);

  for (int i=0; i< count; ++i) {
    aRet += va_arg(aList, int);
  }
  va_end(aList);
 
  return aRet;
}

int Test1(std::initializer_list<int> pList)
{
	int aRet = 0;

	for (auto aVal : pList)
	{
		aRet += aVal;
	}

	return aRet;
}

class Test2
{
public:
	Test2() = default;
	Test2(std::initializer_list<int> pList)
	{
		std::cout << "test 2 : initializer_list constructor : ";

		for (auto aVal : pList)
		{
			std::cout << aVal << ", ";
		}

		std::cout << std::endl;
	}
};


int main()
{
	{	// 함수 인자
		{	// C++98		// va_list
			std::cout << "test 0 : " << Test0( 10, 20, 30, 50 ) << std::endl;
		}

		{	// C++11		// initializer_list
			std::cout << "test 1 : " << Test1( { 10, 20, 30, 50, } ) << std::endl;
		}
	}
	
	{	// std::vector → initializer_list 생성자
		std::vector<int> aList = { 20, 40, 80, 150 };

		std::cout << "std::vector : initializer_list constructor : ";

		for (auto aVal : aList)
		{
			std::cout << aVal << ", ";
		}

		std::cout << std::endl;
	}

	{	// 사용자 클래스 → initializer_list 생성자
		[[maybe_unused]]
		Test2 aList = { 20, 40, 80, 150 };
	}
	
	return 0;
}

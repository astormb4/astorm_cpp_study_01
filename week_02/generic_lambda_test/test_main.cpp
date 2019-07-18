/*
	generic lambdas
		https://riptutorial.com/cplusplus/example/1969/generic-lambdas
		http://egloos.zum.com/sweeper/v/3148068
*/

#include <iostream>
#include <string>


int main()
{
	{	// C++11
		auto Test0 = [](int x) { return x; };

		std::cout << "test 0 :" << Test0(11) << std::endl;		// 람다식의 인자로 int 만 사용 가능
	}

	{	// C++14 : generic lambdas
		auto Test1 = [](auto x) { return x; };

		std::cout << "test 1 :" << Test1(0) << std::endl;
		std::cout << "test 1 :" << Test1(0.0f) << std::endl;
		std::cout << "test 1 :" << Test1("hello") << std::endl;
	}

	{	// C++14 : generic lambdas		// ※ 인자의 형식 추론 (type deduction) 을 통해 반환값의 형식까지 컴파일러가 추론해줌
		auto Test2 = [](auto x, auto y) /* ->decltype(x + y) */
			{ 
				return (x + y);
			};

		std::cout << "test 2 :" << Test2(20, 30) << std::endl;			// OK
		std::cout << "test 2 :" << Test2(123.23, 65) << std::endl;		// OK
		std::cout << "test 2 :" << Test2(std::string("hello"), std::string(" world")) << std::endl;		// OK
//		std::cout << "test 2 :" << Test2(std::string("hello"), 123) << std::endl;		// error	// std::string + int	// C2676: 이항 '+': 'std::string'이(가) 이 연산자를 정의하지 않거나 미리 정의된 연산자에 허용되는 형식으로의 변환을 정의하지 않습니다.
	}

	return 0;
}

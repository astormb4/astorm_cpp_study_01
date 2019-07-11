/*
	variant
		https://en.cppreference.com/w/cpp/utility/variant
		http://occamsrazr.net/tt/323
*/

#include <variant>
#include <iostream>
#include <string>


int main()
{
	std::variant<int, double, std::string> aVal = 123;

	{	// 기본
//		std::cout << aVal << std::endl;		// error	// C2679: 이항 '<<': 오른쪽 피연산자로 'std::variant<int,double,std::string>' 형식을 사용하는 연산자가 없거나 허용되는 변환이 없습니다.

		std::cout << std::get<int>(aVal) << std::endl;		// OK

//		std::cout << std::get<float>(aVal) << std::endl;	// error	// 변수 선언 시 명시한 타입이 아님		// C2338: get<T>(variant<Types...>&) requires T to occur exactly once in Types.

// 		[[maybe_unused]]
// 		auto aRet = std::get<std::string>(aVal);	// exception	// 변수 선언 시 명시한 타입이나 값을 변환할 수 없음		// std::bad_variant_access
	}
	
	{	// std::get_if		// 특정 형식으로 변환이 가능하면 변환 / 불가 시 nullptr 반환
//		auto aRet = std::get_if<bool>(&aVal);	// OK	// nullptr
		auto aRet = std::get_if<int>(&aVal);	// OK
		if (aRet == nullptr)
		{
			std::cout << "std::get_if : nullptr" << std::endl;
		}
		else
		{
			std::cout << "std::get_if : " << (*aRet) << std::endl;			
		}
	}

	{	// std::holds_alternative		// (현재 지원하는 형식에 대해서) 특정 형식으로 변환이 가능한지 여부를 bool 값으로 반환
//		std::cout << "std::holds_alternative : " << std::holds_alternative<float>(aVal) << std::endl;			// error	// 변수 선언 시 명시한 타입이 아님		// error C2338: holds_alternative<T>(const variant<Types...>&) requires T to occur exactly once in Types.
		std::cout << "std::holds_alternative : " << std::holds_alternative<int>(aVal) << std::endl;				// OK		// true
		std::cout << "std::holds_alternative : " << std::holds_alternative<double>(aVal) << std::endl;			// OK		// false
		std::cout << "std::holds_alternative : " << std::holds_alternative<std::string>(aVal) << std::endl;		// OK		// false
	}

	{	// std::variant::index()		// 현재 지정된 값이 어떤 형식에 해당하는지 인덱스로 반환	// ex> aVal → 0: int / 1: double / 2: std::string
		std::cout << "std::variant::index : " << aVal.index() << std::endl;
	}

	return 0;
}

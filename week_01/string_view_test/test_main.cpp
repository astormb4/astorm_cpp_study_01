/*
	string_view
		https://en.cppreference.com/w/cpp/string/basic_string_view
		http://occamsrazr.net/tt/316

	◇ std::string_view			std::basic_string_view<char>
	◇ std::wstring_view		std::basic_string_view<wchar_t>
	◇ std::u8string_view		std::basic_string_view<char8_t>		// C++20
	◇ std::u16string_view		std::basic_string_view<char16_t>
	◇ std::u32string_view		std::basic_string_view<char32_t>
*/

#include <string_view>
#include <iostream>
#include <string>


void Test0(const std::string&& pPrm)
{
	std::cout << "test 0 : " << pPrm << std::endl;
}


void Test1(const std::string_view&& pPrm)
{
	std::cout << "test 1 : " << pPrm << std::endl;
}


std::string_view Test2()
{
	std::string aOrg = "hello world";

	std::string_view aRet = aOrg;

	return aRet;	// error	// string_view 는 참조하고 있는 문자열의 시작 위치 (포인터) + 문자열 길이 만을 가지고 있으므로 임시 객체 등을 참조 중에 함수 반환값으로 사용 시 문제가 발생 가능 → 함수의 출력 인자 등으로 값을 반환하는 방식을 전환 필요
}


int main()
{
	{	// 기본
		Test0("hello world");	// const std::string &			// literal 을 매개변수로 받을 경우에는 임시 객체가 생성됨
		Test1("hello world");	// const std::string_view &		// literal 을 매개변수로 받아도 임시 객체가 생성되지 않음
	}

	std::string aOrg = "hello world";

	{	// std::string_view::remove_prefix

		std::string_view aVal = aOrg;
		
		aVal.remove_prefix(3);

		std::cout << "remove_prefix : " << aVal << std::endl;		// OK		// → lo world
	}

	{	// std::string_view::remove_suffix
		std::string_view aVal = aOrg;

		aVal.remove_suffix(2);

		std::cout << "remove_suffix : " << aVal << std::endl;		// OK		// → hello wor
	}

	return 0;
}

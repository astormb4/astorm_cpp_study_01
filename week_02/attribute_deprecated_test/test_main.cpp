/*
	attribute : deprecated
		https://en.cppreference.com/w/cpp/language/attributes/deprecated
		https://docs.microsoft.com/ko-kr/cpp/cpp/deprecated-cpp?view=vs-2019
*/

#include <iostream>


[[deprecated]]
int g_Val1 = 1050;

[[deprecated("it would be deprecated 1234")]]
float g_Val2 = 2387.3f;

[[deprecated("do not use this function anymore!")]]
void Test1() { std::cout << "hello world" << std::endl; }


int main()
{
	std::cout << g_Val1 << std::endl;		// OK	// C4996
	std::cout << g_Val2 << std::endl;		// OK	// C4996
//	Test1();								// OK	// C4996

	return 0;
}

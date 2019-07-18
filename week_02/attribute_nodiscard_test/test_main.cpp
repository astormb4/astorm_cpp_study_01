/*
	attribute : nodiscard
		https://en.cppreference.com/w/cpp/language/attributes/nodiscard
*/

#include <iostream>


[[nodiscard]]
int Test1(int val1, int val2)
{
	return (val1 + val2);
}

struct[[nodiscard]] MyStruct
{
	int m_Val1 = 0;
};

MyStruct Test2()
{
	return MyStruct{50};
}


int main()
{
	{	// case 1
		std::cout << Test1(10, 20) << std::endl;		// OK

		int aRet = Test1(10, 60);						// OK
		std::cout << aRet << std::endl;

//		Test1(20, 30);		// warning		// C4834: 'nodiscard' 특성이 포함된 함수의 반환 값을 버리는 중

		static_cast<void>(Test1(30, 40));				// OK
	}

	{	// case 2
		Test2();			// warning		// C4834: 'nodiscard' 특성이 포함된 함수의 반환 값을 버리는 중
	}

	return 0;
}

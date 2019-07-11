/*
	constexpr if
		http://egloos.zum.com/sweeper/v/3203973
*/

#include <iostream>


template <typename T>
auto get_value(T t)
{
	if constexpr (std::is_pointer_v<T>)		// ※ 조건이 맞는 구문만 컴파일 대상에 포함되며 나머지 구문(들)은 제외됨
	{
		std::cout << "ptr : ";
		return *t;
	}
	else
	{
		std::cout << "val : ";
		return t;
	}
}


int main()
{
	{	// case 1
		int aVal1 = 100;

		std::cout << "case 1 : " << get_value(&aVal1) << std::endl;
	}

	{	// case 2
		float aVal2 = 563.12f;

		std::cout << "case 2 : " << get_value(aVal2) << std::endl;
	}

	return 0;
}

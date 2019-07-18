/*
	attribute : fallthrough
		https://en.cppreference.com/w/cpp/language/attributes/fallthrough
*/

#include <iostream>


void Test1(int val1, int val2)
{
	switch (val1)
	{
	case 1:
	case 2:
		std::cout << "test 1 : 1" << std::endl;
		[[fallthrough]];	// OK
	case 3:
		std::cout << "test 1 : 2" << std::endl;
		// warning		// 경고 수준에 따라 다름
	case 4:
		std::cout << "test 1 : 3" << std::endl;
		[[fallthrough]];	// OK
	case 5:
		{
			if (val2 <= 0)
			{
				std::cout << "test 1 : 4" << std::endl;
				[[fallthrough]];	// 무시됨		// warning		// C4468: 'fallthrough': 특성 뒤에는 case 레이블 또는 default 레이블이 있어야 합니다.
			}
			std::cout << "test 1 : 5" << std::endl;
		}
	default:
		std::cout << "test 1 : default" << std::endl;
		break;
	}
}


int main()
{
	Test1(1, 10);
//	Test1(5, -1);
//	Test1(5, 20);

	return 0;
}

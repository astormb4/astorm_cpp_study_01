/*
	attribute : maybe_unused
		https://en.cppreference.com/w/cpp/language/attributes/maybe_unused
*/

#include <iostream>
#include <assert.h>


[[maybe_unused]] void Test1(bool val1, bool val2)
{
	[[maybe_unused]] bool b = val1 && val2;

	assert(b);	// release 모드로 컴파일 시 b 는 미사용 변수가 되지만 [[maybe_unused]] 속성으로 인해 컴파일 타임 경고가 발생하지 않음
}


int main()
{
	Test1(true, false);

	return 0;
}

/*
	generalized (lambda) capture / lambda capture expressions
		http://egloos.zum.com/sweeper/v/3148118
		https://riptutorial.com/cplusplus/example/1950/generalized-capture
*/

#include <iostream>
#include <vector>
#include <type_traits>		// std::move
#include <numeric>			// std::accumulate


struct Test1
{
	int m_val;

	int Func0(int val1)		// C++11
	{
		// return [m_val] { return (m_val + val1); } ();	// 클래스 멤버 변수 m_val 을 (바로) 복사할 수 없음

		int val2 = this->m_val;
		return [val1, val2] { return (val2 + val1); } ();	// 클래스 맴버 변수를 별도의 변수에 복사한 이후에 해당 변수를 복사하여 사용 가능했음
	}


	int Func1(int val1)		// C++14
	{
		return [=] { return (m_val + val1); } ();	// 클래스 멤버 변수 m_val 을 복사 캡쳐		// ※ 호출 방식에 주의 → 람다식을 함수의 반환값으로 바로 호출하는 경우의 호출 포맷
	}

	int Func2()		// C++14
	{
//		return [val = m_val] { return val; } ();
		return [m_val = m_val] { return m_val; } ();
	}

/*	// 필요 없음 ???
	int Func2(int val1)
	{
		auto aFunc2 = [=] () { return (m_val + val1); };

		return aFunc2();
	}
*/
};

struct Test2
{
	std::vector<int> m_vec = { 10, 20, 30, 50, 120, 500 };

	int Func1()
	{
		return [vec = std::move(m_vec)] { return std::accumulate(vec.begin(), vec.end(), 0); } ();
//		return[vec = std::move(m_vec), this]{ return std::accumulate(this->m_vec.begin(), this->m_vec.end(), 0); } ();		// ※ (이미) 범용 람다 캡쳐 변수 vec 로 클래스 멤버 변수 m_vec 의 값들이 이동된 후임 
	}
};


int main()
{
	{	// case 0
		Test1 aTest1 { 123 };

		std::cout << "test 1 : " << aTest1.Func1(100) << std::endl;		// OK
		std::cout << "test 1 : " << aTest1.Func2() << std::endl;		// OK
	}

	{	// case 1	// 범용 람다 캡쳐 시 값 이동 (std::move(...)) 사용
		Test2 aTest2;

		std::cout << "test 2 : " << aTest2.Func1() << std::endl;		// OK
	}

	return 0;
}

/*
	uniform initialization
		https://narss.tistory.com/entry/4%EC%9D%BC%EC%B0%A8-%EC%9D%BC%EA%B4%80%EB%90%9C-%EC%B4%88%EA%B8%B0%ED%99%94-Uniform-initialize
		http://sweeper.egloos.com/3058356
*/

#include <iostream>
#include <complex>


struct Test0
{ int x, y; };


int main()
{
	{	// C++11
		{	// 이전		// 상황에 따라 객체 / 목록 초기화 방식이 제각각임
			int n1 = 0;
			int n2(0);
			int x[10] = { 1,2,3,4,5,6,7,8,9,10 };
			Test0 p = { 1, 1 };
			std::complex<int> c(1, 2);
		}

		{	// 개선		// 상황에 무관하게 일관된 초기화 방식을 제공 → 중괄호 { } 를 이용
			int n1{ 0 };
			int n2{ 0 };
			int x[10]{ 1,2,3,4,5,6,7,8,9,10 };
			Test0 p { 1, 1 };
			std::complex<int> c{ 1, 2 };
		}
	}

	{	// C++17
		{	// 이전		// auto 타입 추론 + '{ }' 초기화 시에 객체 / 목록 초기화 방식 간에 모호성이 발생
			int v0 { 123 };			// OK			// int
			auto v1 { 123 };		// OK ?			// std::initializer_list		// 객체 초기화인지 목록 초기화인지 모호함
			auto v2 = { 123 };		// OK ?			// std::initializer_list		// 객체 초기화인지 목록 초기화인지 모호함
//			auto v3 { 1,2,3 };		// error ?		// std::initializer_list		// 객체 초기화인지 목록 초기화인지 모호함 → C++17 에서는 컴파일 오류 발생
			auto v4 = { 1,2,3 };	// OK			// std::initializer_list
		}

		{	// 개선		// (상기와 같은) 모호성을 제거할 수 있도록 객체 / 목록 각각의 초기화 방식을 명확히 분리함 → initializer list 를 통해 목록을 초기화 하고 싶을 경우에는 '={ }' 형태로 전달
			auto v1 { 123 };		// OK			// int
			auto v2 = { 123 };		// OK			// std::initializer_list
//			auto v3 { 1,2,3 };		// error
			auto v4 = { 1,2,3 };	// OK			// std::initializer_list

		}
	}

	return 0;
}

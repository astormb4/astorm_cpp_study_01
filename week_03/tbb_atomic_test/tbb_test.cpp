// tbb_atomic_test.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <tbb/atomic.h>		// https://m.blog.naver.com/PostView.nhn?blogId=hermet&logNo=54482760&proxyReferer=https%3A%2F%2Fwww.google.com%2F

typedef	unsigned long long		TP_TYPE1;


int main()
{
//	tbb::atomic<TP_TYPE1> aVal1 = 0;
	tbb::atomic<TP_TYPE1> aVal1 = static_cast<TP_TYPE1>(0xFFFFFFFFFFFFFFFF);

	TP_TYPE1 aVal2 = ++aVal1;
	aVal1 += 7;

	std::cout << "show 1: " << aVal1 << std::endl;
	std::cout << "show 2: " << aVal2 << std::endl;

	aVal2 = ++aVal1;

	std::cout << "show 2: " << aVal2 << std::endl;
}


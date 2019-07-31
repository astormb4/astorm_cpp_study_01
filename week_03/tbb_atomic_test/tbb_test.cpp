
/*	// VCPKG 관리
	설치>
		vcpkg.exe install tbb					// ※ ':x86-windows' 와 동일
		vcpkg.exe install tbb:x64-windows
		vcpkg.exe install tbb:x86-windows
	제거>
		vcpkg.exe remove tbb					// ※ ':x86-windows' 와 동일
		vcpkg.exe remove tbb:x64-windows
		vcpkg.exe remove tbb:x86-windows
*/

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


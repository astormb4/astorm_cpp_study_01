/*
	r-value reference : move function
		https://docs.microsoft.com/ko-kr/cpp/cpp/move-constructors-and-move-assignment-operators-cpp?view=vs-2019
		https://zepeh.tistory.com/224
*/

#include <iostream>


class Test1
{
public:
	Test1() = default;
	Test1(int pDataLen) { Set(pDataLen); }

	Test1(const Test1& pRv)						// 복사 생성자
	{
		if (pRv.IsSet() == true)
		{ 
			m_Data = new int[pRv.m_DataLen];
			m_DataLen = pRv.m_DataLen;
			::memcpy_s(m_Data, m_DataLen, pRv.m_Data, pRv.m_DataLen);		// ※ deep-copy
		}

		std::cout << "test 1 : copy constructor" << std::endl;
	}

	Test1(Test1&& pRv)							// 이동 생성자		// C++11
	{
		if (pRv.IsSet() == true)
		{
			m_Data = pRv.m_Data;		// ※ move
			m_DataLen = pRv.m_DataLen;
			pRv.Reset();
		}

		std::cout << "test 1 : move constructor" << std::endl;
	}

	Test1& operator =(const Test1& pRv)			// 할당 연산자
	{
		if (pRv.IsSet() == true)
		{
			m_Data = new int[pRv.m_DataLen];
			m_DataLen = pRv.m_DataLen;
		}

		std::cout << "test 1 : assignment operators" << std::endl;

		return (*this);
	}

	Test1& operator =(Test1&& pRv)				// 대입 연산자		// C++11
	{
		if (pRv.IsSet() == true)
		{
			m_Data = new int[pRv.m_DataLen];
			m_DataLen = pRv.m_DataLen;
			pRv.Reset();
		}

		std::cout << "test 1 : move operators" << std::endl;
		
		return (*this);
	}

	~Test1()
	{
		Reset();
	}

	void Set(int pDataLen)
	{
		if (pDataLen < 0) { return; }

		Reset();

		m_Data = new int[pDataLen];
		m_DataLen = pDataLen;
	}

	bool IsSet() const
	{
		return ((m_Data != nullptr) && (m_DataLen > 0));
	}

	void Reset()
	{
		if (m_Data != nullptr)
		{
			delete m_Data;
			m_Data = nullptr;
			m_DataLen = 0;
		}
	}

	int GetDataLen() const { return m_DataLen; }

private:
	int* m_Data = nullptr;
	int m_DataLen = 0;
};


int main()
{
	Test1 aVal1;
	aVal1.Set(100);

//	Test1&& aVal2 = aVal1;					// error	// C2440: '초기화 중': 'Test1'에서 'Test1 &&'(으)로 변환할 수 없습니다.		// lvalue를 rvalue 참조에 바인딩할 수 없습니다.
	Test1&& aVal2 = std::move(aVal1);		// OK		// 이동 생성자

//	Test1&& aVal3 = aVal2;					// error	// ※ aVal2 자체는 r-value 가 아님 → r-value reference 를 통해 값을 받은 것일 뿐임
	
	{	// 복사 생성자
		Test1 aVal4 = aVal2;				// OK
//		Test1 aVal4 (aVal2);				// OK
//		Test1 aVal4 { aVal2 };				// OK		// uniformed initialization (일관된 초기화)
	}

	{	// 이동 생성자			// C++11
		Test1 aVal5 = std::move(aVal2);		// OK
//		Test1 aVal5 (std::move(aVal2));		// OK
//		Test1 aVal5 { std::move(aVal2) };	// OK		// uniformed initialization (일관된 초기화)
	}

	aVal2.Set(100);

	{	// 할당 연산자
		Test1 aVal6;
		aVal6 = aVal2;
	}

	{	// 이동 할당 연산자		// C++11
		Test1 aVal7;
		aVal7 = std::move(aVal2);
	}

	aVal2.Set(200);

	{	// ※ 유의해야 할 경우
		{	// case 1
			Test1&& aVal9 = std::move(aVal2);	// OK		// 복사 생성자가 호출된 것이 아닌 변수 aVal2 에 대한 (좌측값) 참조와 유사하게 처리
			std::cout << "val 9 : " << aVal9.GetDataLen() << " / " << &aVal9 << std::endl;
			std::cout << "val 2 : " << aVal2.GetDataLen() << " / " << &aVal2 << std::endl;

		}
		{	// case 2
			Test1&& aVal9 = Test1(9876);		// OK		// 우측값 참조
			std::cout << "val 9 : " << aVal9.GetDataLen() << " / " << &aVal9 << std::endl;
		}
	}

	return 0;
}

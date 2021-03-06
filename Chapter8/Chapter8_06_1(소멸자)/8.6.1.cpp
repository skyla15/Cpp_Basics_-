// 8.6.1.cpp.cpp: 콘솔 응용 프로그램의 진입점을 정의합니다.
// 함수의 호출의 경우 스택형식으로 쌓이기때문에 
// 0 -> 1 로 쌓였고 pop() pop() 이 실행되는 것임 
// 따라서 생성자0 생성자1 소멸자1 소멸자0 이 실행 

#include "stdafx.h"

#include <iostream>
using namespace std;

class Simple
{
private:
	int m_id;

public:
	Simple(const int& id_in)
		: m_id(id_in)
	{
		cout << "Constructor " << m_id << endl;
	};

	~Simple()
	{
		cout << "Destructor " << m_id << endl;
	}
};

int main()
{
	Simple *s1 = new Simple(0);
	// 힙 영역으로 들어가고 해제가 안됨 
	// 메모리 누수 위험 
	Simple s2(1);

	delete s1;
}

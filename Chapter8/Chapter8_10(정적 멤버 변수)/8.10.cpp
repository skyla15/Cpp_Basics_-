// 정적 멤버 변수
/*
	1) 정적 멤버 변수는 초기화 불가능 
	2) 정적 멤버 상수는 처음에 초기화를 하여야 함 
	   cf) 
	      constexpr : 컴파일 타임에 정의 
		  const : 런타임에 정의될 수도 있는 경우 
	3) 정적 멤버는  cpp 파일로 빼내서 사용할 것 

*/
// 4.2 전역 변수, 정적 변수, 내부 연결, 외부 연결 Global variables, Static variable, Internal linkage, External linkage
//



#include "stdafx.h"
#include <iostream>

using namespace std;

class Something
{
public :
	static int constexpr m_value = 1;
	static int s_value;
};

int Something::s_value = 1;


int main()
{
	Something st1;
	cout << &st1.s_value << " " << st1.s_value << endl;
	Something st2;
	Something::s_value = 3;	
	cout << &st1.s_value << " " << st2.s_value << endl;
    return 0;
}


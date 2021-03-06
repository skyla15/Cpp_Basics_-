// 정적 멤버 변수
/*
	1) 정적 멤버 변수는 생성자 및 클래스 내부에서 초기화 불가능.
	   => 클래스에서 공유하는 변수이므로 매번 생성할 때마다 초기화하는 것은 말이 안됨 
	   => 초기화 방법
	      1-1) 클래스 외부에서 초기화  *******
		  1-2) 내부클래스 선언 뒤 정적 내부클래스 인스턴스를 만들어 초기화하면서 사용 . *********
	   => 비정적 멤버 변수??
	      => 클래스 외부에서 초기화 불가능 

	2) static 멤버함수는 객체에 종속적이지 않다.
	   => 객체에 종속적이지 않기때문에 this 사용 불가능 
	   => 정적 멤버함수는 객체 생성 전에 이미 존재한다
	   => 객체의 생성없이 사용이 가능
	   => 객체의 멤버함수로도 사용이 가능

	3) 정적 멤버 상수는 처음에 초기화를 하여야 함
	  cf)
		constexpr : 컴파일 타임에 정의
		const : 런타임에 정의될 수도 있는 경우

	4) 정적 멤버는  cpp 파일로 빼내서 사용할 것
	
	5) static 멤버 함수의 경우 this 포인터를 사용 불가능 
	   왜냐하면 인스턴스에 종속적이지 않고 사용이 가능하기 때문에 

	6) non static 멤버 함수의 경우에는 this 포인터를 이용하여 
	   해당 클래스의 멤버함수를 가르키는 포인터를 this->func 식으로 사용 

	7) non-static 멤버함수는 객체에 종속적이다
	   => this 포인터가 생략되어있는 것
*/

#include "stdafx.h"
#include <iostream>

using namespace std;

class Something
{
private :
	static int s_value;
	int m_value;

public : 
	static int getValue() // 객체 선언없이 스태틱 멤버변수 접근 가능 
	{
		return s_value;
	}

	int temp()
	{
		return this->s_value;
	}
};

// int Something::m_value = 1; 비정적멤버변수는 클래스 내부에서 초기화

int Something::s_value = 1024;


int main()
{
	Something st1;
	
	// ( 1 ) 
	/*
		객체 선언 없이
		해당 클래스의 Static Memeber Variable에 접근하고 싶을 경우
		정적 멤버 함수를 선언하여 호출
	*/
	std::cout << Something::getValue() << endl;
	std::cout << st1.getValue() << endl;


	// ( 2 ) 
	/*
		**** 멤버 함수에 대한 함수포인터 사용 방법 ****

		멤버함수 사용 시 s1, s2의 인스턴스 주소는 다름
		그러나 각 객체에 속하는 멤버 함수들은 같은 곳에 저장되어있음 
		각 s1, s2에서 멤버 함수를 사용할 때 
		각 객체에 this포인터를 준뒤에 
		해당 멤버 함수들에 대한 포인터를 주고 사용

	*/
	int(Something::*fptr1)() = &Something::temp;
	// int(Something::*fptr1)() = &s1.temp; 에러 
	/*
		this == &st1
		this->(*fptr1) == this->tmep();
		같은 의미
	*/
	cout << (st1.*fptr1)() << endl;


	// ( 3 ) 
	// int(Something::*fptr2)() = &Something::getValue;
	// 에러. Static의 경우 특정 인스턴스와 상관없이 실행시킬 수 있는 함수로 생각 
	int(*fptr2)() = &Something::getValue;
	cout << fptr2() << endl;

	

	return 0;
}






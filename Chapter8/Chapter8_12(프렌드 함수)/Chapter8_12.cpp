/*
	Friend 함수 
	1) "연산자 오버로딩"에서 주로 사용 
	2) 클래스의 private 멤버에 접근하기 위해서 Freind 연산자를 사용 
	3) 여러 클래스의 멤버에 접근하고자 하는 경우 
	   => 클래스들을 Forward Declaration을 이용하여 사용 
	4) 다른 클래스가 자신의 Private 멤버에 접근을 허용할 때 사용
	5) 다른 클래스의 특정 멤버함수만 friend로 선언 가능 

	** 오류 발생 시 선언 및 정의를 나누어 본다 **
*/


#include "stdafx.h"
#include <iostream>

using namespace std;

class A;

class B
{
private:
	int m_value = 2;
	friend void doSomething(A& a, B& b);

public:
	void doSomething(A& a);
};


class A
{
private : 
	int m_value = 1;
	friend void doSomething(A& a, B& b);
	// friend class B;
	// 특정 멤버 함수들만 freind로 선언 
	friend void B::doSomething(A& a);
	

public:
 
};


void B::doSomething(A& a)
{
	cout << a.m_value << endl;
}





void doSomething(A& a, B& b)
{
	cout << a.m_value << " " << b.m_value << endl;
}

int main()
{
	A a;
	B b;
	doSomething(a, b);
	b.doSomething(a);

    return 0;
}


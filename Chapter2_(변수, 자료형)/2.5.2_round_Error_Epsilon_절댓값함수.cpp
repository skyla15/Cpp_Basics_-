#include <iostream>
#include <float.h>// float의 머신 엡실론 값 FLT_EPSILON이 정의된 헤더 파일
#include <math.h>// float의 절댓값을 구하는 fabsf 함수를 위한 헤더 파일

/*
    < 정수형 절댓값 >
	int         abs( int n );
	long        labs( long n );
	long long   llabs( long long n );

	< 실수형 절댓값 >
	float       fabsf(float arg);
	double      fabs(double arg);
	long double fabsl(long double arg);
*/

using namespace std;
int main()
{
	float num1 = 0.0f;
	float num2 = 0.1f;

	// 0.1을 10번 더함
	for (int i = 0; i < 10; i++)
	{
		num1 = num1 + num2;
	}


	cout << "EPSILON : " << FLT_EPSILON << endl;
	cout << fabsf(num1 - 1.0f) << endl;

	// num1: 1.000000119209290
	if (fabsf(num1 - 1.0f) <= FLT_EPSILON)    
                        // 연산한 값과 비교할 값의 차이를 구하고 절댓값으로
											  // 만든 뒤 FLT_EPSILON보다 작거나 같은지 판단
											  // 오차가 머신 엡실론 이하라면 같은 값으로 봄

		cout << "true" << endl;   // 값의 차이가 머신 엡실론보다 작거나 같으므로 true
	else
		cout << "false" << endl;

	return 0;
}


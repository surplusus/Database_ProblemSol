#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int OUTPUT_LiMIT = 1000000007;
//INT_MAX = 2,147,483,647		// 1,000,000,007
//LLONG_MAX = 9,223,372,036,854,775,807;

// Loop func
unsigned long long 질병통제센터1(int A, int B, unsigned long long T)
{
	unsigned long long result = B;	//T = 1 일때 값과 같다.
	T /= 2;
	while (true)
	{
		// (탈출)T=0 일때 1을 곱하는 것이므로 나온다.
		if (T == 0)
			break;
		//일단 2배로 만든다
		result = result * result;
		// T가 홀수 이면 B만 한번더 곱한다
		if (T % 2 == 1)
			result *= B;

		result %= OUTPUT_LiMIT;
		T /= 2;
	}

	return A * result;
}
// recursive func
unsigned long long 질병통제센터2(int B, unsigned long long T)
{
	/*
		A * B * T
		문제는 T만 바뀐다
		만약 초기 T 값이 7이라면
			AB * 7
		둘로 나눈다면(작은단위로 쪼개기)
			(A*B*3) * (A*B*3) * B
		더이상 나눌수 없을때(재귀 탈출 부분)
			A*B^0
	*/
	// 재귀 탈출 부분(제일 작은 단위)
	// (반드시 재귀함수 위에 존재해야됨)
	if (T == 0)
		return 1;

	// 재귀 진입 부분
	unsigned long long recur = 질병통제센터2(B, T / 2);

	// (예외) T가 1일때, B를 두번 곱할일이 없다
	if (T == 1)
		return recur * B;

	// 작은 단위로 쪼개진 이후 실행할 일들
	unsigned long long result = recur * recur;
	// (예외)T가 홀수 일때
	if (T % 2 == 1)
		result *= B;

	result %= OUTPUT_LiMIT;
	return result;
}

int main()
{
	int A, B;
	unsigned long long T;
	cin >> A >> B >> T;
	cout << endl;
	cout << endl;
	unsigned long long res1 = 질병통제센터1(A, B, T) % OUTPUT_LiMIT;
	unsigned long long res2 = (질병통제센터2(B, T) * A) % OUTPUT_LiMIT;
	cout << res1 << endl;
	cout << res2 << endl;

	return 0;
}
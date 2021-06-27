// Baekjoon / problem / 1629
// 곱셈 (거듭제곱, 여러방법으로 해결, 리펙토링)

#include <iostream>
using namespace std;

#pragma region O(N)
long long power_recursive(long b, int p)	// b : Base  // p : Power
{
	if (p == 0)
		return 1;

	return b * power_recursive(b, p - 1);
}
long power_loop(int b, int p)
{
	long result = 1;
	if (p == 0) {
		return result;
	}

	for (size_t i = 0; i < p; i++)
	{
		result *= b;
	}
	return result;
}
#pragma endregion
#pragma region O(logN)
// 밑이 3이고 지수(n)가 짝수일 때 : 3^n = 3^n/2 x 3^n/2
// 밑이 3이고 지수(n)가 홀수일 때 : 3^n = 3^(n-1)/2 x 3^(n-1)/2 x 3
long long power_refec_recursive(long long b, int p)
{
	if (p == 0)
		return 1;
	
	long long tmp = power_refec_recursive(b, p / 2);
	if (p % 2 == 0)
		return tmp * tmp;
	else
		return tmp * tmp * b;
}
long power_refec_loop(int b, int p)  // 실패 loop 버전은 안되나봄
{
	if (p == 0)
		return 1;
	int result = b;
	int pow = p;
	while (pow>0)
	{
		pow /= 2;
		result *= result;
		if (pow % 2 == 1)
		{
			result *= b;
		}
	}
	
	return result;
}
#pragma endregion

long long power(int b, int p, int divisor)
{
	if (p == 0)
		return 1;
	long long tmp = power(b, p / 2, divisor);
	long long n = (tmp * tmp) % divisor;			// 요 부분을 넣어야만 overflow 안난다
	if (p % 2 == 0)
		return n;
	else
		return (n * b) % divisor;
}
int main()
{
	cout << power_recursive(10, 11) << endl;
	cout << power_loop(2, 5) << endl;
	cout << power_refec_recursive(10, 11) << endl;
	cout << power_refec_loop(2,5) << endl;
	int A, B, C;
	//cin >> A >> B >> C;
	A = 1234556; B = 11000; C = 10;
	cout << power(A, B, C) << endl;
	return 0;
}
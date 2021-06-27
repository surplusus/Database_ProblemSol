#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 98765
using namespace std;

static bool isNotPrime[MAX];

void SieveOfEratosthenes()
{
	memset(isNotPrime, false, sizeof(isNotPrime));
	isNotPrime[0] = true;
	isNotPrime[1] = true;
	for (long i = 2; i < sqrt(MAX); ++i)
	{
		if (!isNotPrime[i])
		{
			for (int j = i * i; j < MAX; j += i)
			{
				isNotPrime[j] = true;
			}
		}
	}
}

static bool IsPrime(long num)
{
	return !isNotPrime[num];
}

int main()
{
	SieveOfEratosthenes();
	long n;
	cin >> n;
	if (IsPrime(n))
		cout << "�Ҽ��Դϴ�." << endl;
	else
		cout << "�Ҽ��� �ƴմϴ�." << endl;
	return 0;
}
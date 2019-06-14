#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int OUTPUT_LiMIT = 1000000007;
//INT_MAX = 2,147,483,647		// 1,000,000,007
//LLONG_MAX = 9,223,372,036,854,775,807;

// Loop func
unsigned long long ������������1(int A, int B, unsigned long long T)
{
	unsigned long long result = 1;	//T = 0 �϶� ���� ����.
	unsigned long long npow = B;
	while (true)
	{
		// T�� Ȧ�� �̸�
		if (T % 2 == 1)
		{
			// 2 �� ����� ���� ���Ѵ�.
			result *= npow;
			result %= OUTPUT_LiMIT;
			// (Ż��)T=1 �϶� B�� ���ϰ� ���´�.
			if (T == 1)
				break;
		}

		// 2��� �����
		npow = npow * npow;
		npow %= OUTPUT_LiMIT;
		
		T /= 2;
	}
	result = A * result % OUTPUT_LiMIT;
	return result;
}
// recursive func
unsigned long long ������������2(int B, unsigned long long T)
{
	/*
		A * B * T
		������ T�� �ٲ��
		���� �ʱ� T ���� 7�̶��
			AB * 7
		�ѷ� �����ٸ�(���������� �ɰ���)
			(A*B*3) * (A*B*3) * B
		���̻� ������ ������(��� Ż�� �κ�)
			A*B^0
	*/
	// ��� Ż�� �κ�(���� ���� ����)
	// (�ݵ�� ����Լ� ���� �����ؾߵ�)
	if (T == 0)
		return 1;

	// ��� ���� �κ�
	unsigned long long recur = ������������2(B, T / 2);

	// (����) T�� 1�϶�, B�� �ι� �������� ����
	if (T == 1)
		return recur * B % OUTPUT_LiMIT;

	// ���� ������ �ɰ��� ���� ������ �ϵ�
	unsigned long long result = recur * recur;
	result %= OUTPUT_LiMIT;
	
	// (����)T�� Ȧ�� �϶�
	if (T % 2 == 1)
	{
		result *= B;
		result %= OUTPUT_LiMIT;
	}
	return result;
}

int main()
{
	int A, B;
	unsigned long long T;
	cin >> A >> B >> T;
	cout << endl;
	cout << endl;
	unsigned long long res1 = ������������1(A, B, T) % OUTPUT_LiMIT;
	unsigned long long res2 = (������������2(B, T) * A) % OUTPUT_LiMIT;
	cout << res1 << endl;
	cout << res2 << endl;

	return 0;
}
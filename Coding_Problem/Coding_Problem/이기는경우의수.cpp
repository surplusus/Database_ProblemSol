#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	cout << "���� �� �Է� : ";
	int numMember;
	cin >> numMember;
	vector<size_t> numCard(numMember * 2);

	// �� ���� �����ϰ� ����ī�带 ����
	vector<size_t> tA(numMember);
	vector<size_t> tB(numMember);
	for (int i = 0; i < numMember ; ++i)
		tA[i] = (size_t)rand() % 100000;
	for (int i = 0; i < numMember; ++i)
		tB[i] = (size_t)rand() % 100000;

	cout << "�� A�� ���� ī�� : ";
	for (size_t i = 0; i < numMember; i++)
		cout << tA[i] << " ";
	cout << endl;
	cout << "�� B�� ���� ī�� : ";
	for (size_t i = 0; i < numMember; i++)
		cout  << tB[i] << " ";
	cout << endl;

	// ����� ��A(tmp)�� ��B�� ����
	vector<size_t> tmp(tA);
	sort(tmp.begin(), tmp.end());
	sort(tB.begin(), tB.end());

	// ����� ��A�� ���� ���� ���ں��� �̱�� �ִ��� �Ǻ�
	unsigned int result = 0;
	for (size_t i = 0; i < tmp.size(); i++)
	{
		vector<size_t>::iterator n = lower_bound(tB.begin(), tB.end(), tmp[i]);
		// ����ó�� (lower_bound���� ū ���� ������ end iterator�� ����Ų��)
		if (n == tB.end())
			break;
		// ���� tmp�� ���� ���� ���ں��� ���ʷ� ��
		if (*n > tmp[i])
			result++;

		tB.erase(n);
	}
	cout << "�̱�� Ƚ�� : ";
	cout << result;
	return 0;
}
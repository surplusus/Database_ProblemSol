#include <iostream>
#include <vector>
#include <iterator>
#include <algorithm>
#include <ctime>

using namespace std;

int main()
{
	cout << "팀원 수 입력 : ";
	int numMember;
	cin >> numMember;
	vector<size_t> numCard(numMember * 2);

	// 두 팀이 랜덤하게 숫자카드를 뽑음
	vector<size_t> tA(numMember);
	vector<size_t> tB(numMember);
	for (int i = 0; i < numMember ; ++i)
		tA[i] = (size_t)rand() % 100000;
	for (int i = 0; i < numMember; ++i)
		tB[i] = (size_t)rand() % 100000;

	cout << "팀 A가 뽑은 카드 : ";
	for (size_t i = 0; i < numMember; i++)
		cout << tA[i] << " ";
	cout << endl;
	cout << "팀 B가 뽑은 카드 : ";
	for (size_t i = 0; i < numMember; i++)
		cout  << tB[i] << " ";
	cout << endl;

	// 복사된 팀A(tmp)와 팀B를 정렬
	vector<size_t> tmp(tA);
	sort(tmp.begin(), tmp.end());
	sort(tB.begin(), tB.end());

	// 복사된 팀A의 가장 작은 숫자부터 이길수 있는지 판별
	unsigned int result = 0;
	for (size_t i = 0; i < tmp.size(); i++)
	{
		vector<size_t>::iterator n = lower_bound(tB.begin(), tB.end(), tmp[i]);
		// 예외처리 (lower_bound보다 큰 값이 없으면 end iterator를 가리킨다)
		if (n == tB.end())
			break;
		// 백터 tmp의 가장 작은 숫자부터 차례로 비교
		if (*n > tmp[i])
			result++;

		tB.erase(n);
	}
	cout << "이기는 횟수 : ";
	cout << result;
	return 0;
}
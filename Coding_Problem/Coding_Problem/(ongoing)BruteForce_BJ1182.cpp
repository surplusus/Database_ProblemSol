// Baekjoon / problem / 1182
// 부분수열의 합 (Brute Force)

#include <iostream>
#include <vector>
using namespace std;

int result = 0;

void DFS(int sum, int idx, vector<int>& que, int gool)
{
	if (idx >= que.size())
		return;

	int sum = 0;

	for (int i = idx; i < Size; i++)
	{
		sum += que[i];
		for (int j = i + 1; j < Size; j++)
		{
			DFS
		}
	}

	if (sum == gool)
	{
		res++;
	}
}

int main()
{
	int N, S = 0;
	cin >> N >> S;
	vector<int> query;
	int cnt = N;
	while (cnt--)
	{
		int tmp;
		cin >> tmp;
		query.push_back(tmp);
	}

	DFS(0, query, S);
	return 0;
}
// Baekjoon / problem / 10974
// 모든 순열 (DFS)

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void Pick(int n, vector<int>& picked, vector<bool>& visit)
{
	if (picked.size() == n)
	{
		for (auto& it : picked)
			cout << it << ' ';
		cout << '\n';
	}
	for (int i = 1; i <= n; ++i)
	{
		if (visit[i])
			continue;
		visit[i] = true;
		picked.push_back(i);
		Pick(n, picked, visit);
		picked.pop_back();
		visit[i] = false;
	}
}

int main()
{
	int N;
	cin >> N;
	vector<int> picked;
	vector<bool> visit = vector<bool>(N + 1, false);
	Pick(N, picked, visit);
	return 0;
}
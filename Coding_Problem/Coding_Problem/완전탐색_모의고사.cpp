// programmers problem / 완전탐색 
// 모의고사
#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <set>

using namespace std;

vector<int> solution(vector<int> answers) {
	vector<int> answer;
	typedef pair<int, int> RANK;
	vector<int> supo1 = { 1,2,3,4,5 };
	vector<int> supo2 = { 2,1,2,3,2,4,2,5 };
	vector<int> supo3 = { 3,3,1,1,2,2,4,4,5,5 };
	auto it1 = supo1.begin();
	auto it2 = supo2.begin();
	auto it3 = supo3.begin();
	vector<int> OK_supo(3, 0);
	//set<pair<int, int>> OK_supo;
	//priority_queue<RANK, vector<RANK>, greater<RANK> > OK_supo;
	for (int i = 0; i < answers.size(); ++i)
	{
		if (answers[i] == *(it1 + i % 5)) ++OK_supo[0];
		if (answers[i] == *(it2 + i % 8)) ++OK_supo[1];
		if (answers[i] == *(it3 + i % 10)) ++OK_supo[2];
	}
	set<int> r;
	for (int i = 0; i < OK_supo.size(); i++)
	{
		r.insert(-OK_supo[i]);
	}
	/*	다른 풀이
		#include <algorithm>
		int nMax = max_element(OK_supo.begin(), OK_supo.end());
		for (int i = 0; i < OK_supo.size(); ++i)
			if (OK_supo[i] == nMax)	answer.push_back(i + 1);
	*/

	int a = -(*(r.begin()));
	if (a == OK_supo[0]) answer.push_back(1);
	if (a == OK_supo[1]) answer.push_back(2);
	if (a == OK_supo[2]) answer.push_back(3);
	
	return answer;
}

int main()
{
	vector<int> a = { 1,2,3,4,5 };
	
	vector<int> result = solution(a);
	for (int i = 0; i < result.size(); i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}
// HackerRank problem 
// Candies
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
#include <functional>
using namespace std;

//struct Quary
//{
//    int Q;
//    string S;
//};
//int main() {
//    int n;
//    cin >> n;
//    stack<Quary> undo;
//    string result;
//    while (n--)
//    {
//        int check4;
//        Quary qua;
//        string buffer;
//        cin >> check4;
//        if (check4 == 4)
//        {
//            undo.pop();
//            qua = undo.top();
//            check4 = qua.Q;
//        }
//        int idx = 0;
//        switch (check4)
//        {
//        case 1:
//            cin >> buffer;
//            result += buffer;
//            qua.Q = 1; qua.S = buffer;
//            undo.push(qua);
//            break;
//        case 2:
//            int cntdown;
//            cin >> cntdown;
//            buffer = result.substr(result.length() - cntdown, cntdown);
//            result.erase(result.end() - cntdown, result.end());
//            qua.Q = 2; qua.S = buffer;
//            undo.push(qua);
//            break;
//        case 3:
//            int idx;
//            cin >> idx;
//            cout << result[idx - 1] << endl;
//            break;
//        }
//        
//    }
//    return 0;
//}

void Append(string& result, string value)
{
	result += value;
}

void Delete(string& result, int value)
{
	//int n = stoi(value);
	result.erase(result.end() - value, result.end());
}

void Print(string& result, int value)
{
	//int n = stoi(value);
	cout << result[value-1] << endl;
}

int main() {
	function<void(void)> func;
	//stack<function<void(string&, string)>> undo;
	stack < function<void(void)>> undo;
	int cnt;
	string result;
	string s; int n;
	cin >> cnt;
	while (cnt--)
	{
		int Q; cin >> Q;
		switch (Q)
		{
		case 1:
			cin >> s;
			Append(result, s);
			func = [&result, s]() {Delete(result, s.length()); };
			undo.push(func);
			break;
		case 2:
			cin >> n;
			s = result.substr(result.length() - n, n);
			Delete(result, n);
			func = [&result, s]() {Append(result, s); };
			undo.push(func);
			break;
		case 3: 
			cin >> n;
			Print(result, n);
			break;
		case 4:
			func = undo.top();
			func();
			undo.pop();
			break;
		}
	}

	return 0;
}
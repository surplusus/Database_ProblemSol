// baekjoon problem / 9012 
// °ýÈ£

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
	stack<int> brace; // ( : 1  // ) : -1
	string input[60];
	int T = 0;
	int cntBrace;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < T; i++)
	{
		cntBrace = 0;
		
		for (int j = 0; j < input[i].size(); j++)
		{
			if (input[i][0] != '(')
			{
				cout << "NO" << endl;
				break;
			}

			if (input[i][j] == '(')
				brace.push(1);
			if (input[i][j] == ')')
				brace.push(-1);
		}
		while (brace.size())
		{
			cntBrace += brace.top();
			brace.pop();
		}
		if (cntBrace == 0)
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
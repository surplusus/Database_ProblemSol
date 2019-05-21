// baekjoon problem / 9012 
// °ýÈ£

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int ValidPS(string s)
{
	stack<char> paren; // ( : 1  // ) : -1 // parenthesis

	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
			paren.push('(');
		else
		{
			if (!paren.empty())
				paren.pop();
			else
				return 0;
		}
	}
	return s.empty();
}

int main()
{
	int T = 0;
	string input[51];
	cin >> T;

	for (int i = 0; i < T; i++)
	{
		cin >> input[i];
	}

	for (int i = 0; i < T; i++)
	{
		if (ValidPS(input[i]))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;
	}

	return 0;
}
// baekjoon problem / 9012 
// °ýÈ£

#include <iostream>
#include <string>
#include <stack>
using namespace std;

int ValidPS(string s)
{
	stack<char> paren;  // parenthesis

 	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '(')
		{
			paren.push('(');

		}
		if (s[i] == ')')
		{
			if (!paren.empty())
			{
				paren.pop();

			}
			else
			{
				return 0;
			}
		}
	}
	return paren.empty();
}

int main()
{
	int T = 0;
	string input;
	cin >> T;
	while (T--)
	{
		cin >> input;

		if (ValidPS(input))
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}
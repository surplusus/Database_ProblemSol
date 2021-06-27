// HackerRank problem 
// Caeser Cipher

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

#include <sstream>
string caesarCipher(string s, int k) {
	int idx = 0;
	string result = "";
	while (idx < s.length())
	{
		int n = s[idx];
		if (s[idx] >= 'a' && s[idx] <= 'z')
		{
			n += k;
			if (n > 'z')
				n = n - 'z' + 'a' - 1;
			else if (n < 'a')
				n = n + 'z' - 'a';
		}
		else if (s[idx] >= 'A' && s[idx] <= 'Z')
		{
			n += k;
			if (n > 'Z')
				n = n - 'Z' + 'A' - 1;
			else if (n < 'A')
				n = n + 'Z' - 'A';
		}
		result.push_back(n);
		idx++;
	}
	return s;
}

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string s;
	getline(cin, s);

	int k;
	cin >> k;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string result = caesarCipher(s, k);

	cout << result << "\n";

	return 0;
}
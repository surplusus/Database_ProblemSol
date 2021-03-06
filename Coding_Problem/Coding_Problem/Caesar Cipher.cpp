// HackerRank problem 
// Array Manipulation

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

string caesarCipher(string s, int k) {
	string result;
	int idx = 0;

	while (idx < s.length())
	{
		int tmp = s[idx];

		if (s[idx] >= 'a' && s[idx] <= 'z')
		{
			tmp -= 'a' - k;
			tmp %= 26;
			tmp += 'a';
		}
		else if (s[idx] >= 'A' && s[idx] <= 'Z')
		{
			tmp -= 'A' - k;
			tmp %= 26;
			tmp += 'A';
		}
		result.push_back((char)tmp);
		++idx;
	}
	
	return result;
}

// �ٸ� Ǯ��
//string caesarCipher(string s, int k) {
//	for (int i = 0; i < s.length(); i++)
//	{
//		if (isalpha(s[i]))
//		{
//			char a = isupper(s[i]) ? 'A' : 'a';
//			s[i] = a + (s[i] - a + k) % 26;
//		}
//	}
//	return s;
//}

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
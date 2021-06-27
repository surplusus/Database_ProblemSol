// HackerRank problem 
// Strong Password


#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
using namespace std;

#pragma region 비효율 버전
bool has_digit(string password)
{
	int size = password.length();
	while (size--)
	{
		string s = { password[size] };
		if (atoi(s.c_str()) != 0 || s.compare("0") == false)
			return true;
	}
	return false;
}
bool has_lower_char(string password)
{
	int size = password.length();
	while (size--)
	{
		if (islower(password[size]))
			return true;
	}
	return false;
}
bool has_upper_char(string password)
{
	int size = password.length();
	while (size--)
	{
		if (isupper(password[size]))
			return true;
	}
	return false;
}
bool has_special_char(string password)
{
	int size = password.length();
	string special = "!@#$%^&*()-+";
	int size_special = special.length();
	while (size_special--)
	{
		auto it = password.find(special[size_special]);
		if (it != string::npos)
			return true;
	}
	return false;
}
// Complete the minimumNumber function below.
int minimumNumber1(int n, string password) {
	// Return the minimum number of characters to make the password strong
	int result = 0;
	if (!has_digit(password))
		++result;
	if (!has_lower_char(password))
		++result;
	if (!has_upper_char(password))
		++result;
	if (!has_special_char(password))
		++result;
	int cntChar = 6 - n - result;
	if (cntChar > 0)
		result += cntChar;
	return result;
}

#pragma endregion

#pragma region find_if
bool has_special(char element)
{
	static const string special = "!@#$%^&*()-+";
	auto found = special.find(element);
	return found != string::npos ? true : false;
}
int minimumNumber2(int n, string password)
{
	static const int minLength = 6;
	int result = 0;

	vector<function<int(int)>> vFunc1;
	vFunc1.push_back(isdigit);
	vFunc1.push_back(islower);
	vFunc1.push_back(isupper);

	vector<function<int(int)>> vFunc = {
		isdigit, islower, isupper
	};
	for (auto & it : vFunc)
	{
		function<int(int)> cf = it;
		function<bool(char)> func1 = [&cf](char element) ->bool {return cf(element) ? true : false; };
		auto jt = find_if(password.cbegin(), password.cend(), func1);
		if (jt == password.cend())
			++result;
	}
	auto it = find_if(password.cbegin(), password.cend(), has_special);
	if (it == password.cend())
		++result;

	int cntChar = 6 - n - result;
	if (cntChar > 0)
		result += cntChar;

	return result;
}
#pragma endregion

int main()
{
	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string password;
	cin >> password;

	//int answer = minimumNumber1(n, password);
	int answer = minimumNumber2(n, password);
	cout << answer << "\n";

	return 0;
}
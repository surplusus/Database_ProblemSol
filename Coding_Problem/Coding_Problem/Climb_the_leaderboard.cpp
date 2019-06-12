#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	
	int asize = alice.size();
	vector<int> result((int)alice.size());

	// ���� �ߺ��� ����
	vector<int>::iterator new_end = unique(scores.begin(), scores.end());
	scores.erase(new_end, scores.end());
	scores.shrink_to_fit();
	int sSize = scores.size();

	// ����Ž��
	int left, right, mid;
	for (int i = 0; i < asize; i++)
	{
		left = 0; right = sSize - 1;
		if (alice[i] >= scores[left])
		{
			result[i] = 1;
			continue;
		}
		else if (alice[i] < scores[right])
			result[i] = sSize + 1;
		else
		{
			while (left + 1 != right)
			{
				mid = (left + right) / 2;
				if (scores[mid] == alice[i])
				{
					result[i] = mid +1;
					break;
				}
				else
				{
					if (alice[i] < scores[mid])
						left = mid;
					else
						right = mid;
				}
				result[i] = (left +1)+1;
			}
		}
	}
	
	return result;
}

int main()
{
	using namespace std;
	int scores_count;
	cin >> scores_count;
	// numeric_limits<������Ÿ��>::max()  ������Ÿ�Կ��� �ִ� ���� ǥ��
	// cin.ignore(�ѹ��� �о���� ���ڰ���, �о���� �� �Է��� ����)
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string scores_temp_temp;
	getline(cin, scores_temp_temp);
	
	vector<string> scores_temp = split_string(scores_temp_temp);

	vector<int> scores(scores_count);

	for (int i = 0; i < scores_count; i++) {
		int scores_item = stoi(scores_temp[i]);
		scores[i] = scores_item;
	}

	int alice_count;
	cin >> alice_count;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	string alice_temp_temp;
	getline(cin, alice_temp_temp);

	vector<string> alice_temp = split_string(alice_temp_temp);

	vector<int> alice(alice_count);

	for (int i = 0; i < alice_count; i++) {
		int alice_item = stoi(alice_temp[i]);
		alice[i] = alice_item;
	}

	vector<int> result = climbingLeaderboard(scores, alice);

	for (int i = 0; i < result.size(); i++) {
		cout << result[i];

		if (i != result.size() - 1) 
			cout << "\n";
	}

	cout << "\n";
	return 0;
}
 // ���ڿ��� tokenize �Ͽ� vector�� �ֱ�
vector<string> split_string(string input_string) {
	// vector �ߺ�����
	// iterator new_end�� unique �Լ��� �Ἥ �ߺ��Ǵ� ���� ���� �ڿ� �����Ⱚ���� ������
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		////////////////////////////////////////////////////[](const char &x, const char &y) �̰ǹ���?
		// unique �ѵ� ����� ó���� ���ٸ� 
		return x == y and x == ' ';
		//////////////////////////////////////////////////// �̷��Ե� �����Ҽ��ֳ�?
	});
	// unique�� �����Ⱚ�� ù��° �ε���(�Ǵ� �ݺ���)�� ��ȯ�Ѵ�
	// erase(����� ������ ��ġ, ����� ��������ġ)�Լ��� �����Ⱚ�����
	input_string.erase(new_end, input_string.end());

	// ���ڿ� �ڿ� ����(' ')�� ������ ������(string.pop_back())
	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		// ������ ����������(pos����) splits�� ����(substr)�ϱ�
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}
	// ������ token�� ���Ҵ�!!
	// ������ token�� splits�� �־��ֱ�
	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

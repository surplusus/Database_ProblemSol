#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iterator>

using namespace std;

vector<string> split_string(string);

// Complete the climbingLeaderboard function below.
vector<int> climbingLeaderboard(vector<int> scores, vector<int> alice) {
	//using std::iterator;
	//int sSize = scores.size();
	//int asize = alice.size();
	//vector<int> result((int)alice.size());
	//// score��ŭ �Ҵ��ϰ�
	//vector<int> sCpy((int)scores.size());
	//// score�� �����ϰ�    copy(���� ���� ��ġ, ���� ����ġ, ���� ������ ��)
	//copy(scores.begin(), scores.end(), sCpy.begin());
	//
	///*  �����ϴ� �ٸ� ���
	//sCpy.clear();
	//sCpy.assign(scores.begin(), scores.end());
	//*/
	//
	//// iterator(��ȯ �����Ϳ���)�� �Ҵ��Ѵ�
	//vector<int>::iterator new_end = unique(sCpy.begin(), sCpy.end());
	//// �ߺ��� �����    vector.erase(����� ������ ��ġ �ٷ���, ����� ������ġ)
	//sCpy.erase(new_end, sCpy.end());
	////// vector1�� ��� ���ҵ��� ǥ�� ��� ��Ʈ������ ���
	////copy(vector1.begin(), vector1.end(), ostream_iterator<int>(cout, " "));
	////cout << endl;
	//int i = 0;
	//while (i != alice.size())
	//{
	//	result[i] = 1;
	//	for (new_end = sCpy.begin(); new_end != sCpy.end(); ++new_end)
	//	{
	//		if (alice[i] < *new_end)
	//			result[i] += 1;
	//		else
	//			break;
	//	}
	//	i++;
	//}
	int sSize = scores.size();
	int asize = alice.size();
	vector<int> result((int)alice.size());

	vector<int>::iterator new_end;
	for (int i = 0; i < asize; ++i) {
		result[i] = 1;
		for (new_end = scores.begin(); new_end != scores.end(); ++new_end) {
			if (alice[i] < *new_end)
			{
				if (new_end != scores.begin())
					if (*(new_end - 1) == *new_end)
						continue;
				result[i] += 1;
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

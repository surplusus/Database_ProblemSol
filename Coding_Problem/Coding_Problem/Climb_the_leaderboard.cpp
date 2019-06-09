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
	//// score만큼 할당하고
	//vector<int> sCpy((int)scores.size());
	//// score를 복사하고    copy(복사 시작 위치, 복사 끝위치, 복사 시작할 곳)
	//copy(scores.begin(), scores.end(), sCpy.begin());
	//
	///*  복사하는 다른 방법
	//sCpy.clear();
	//sCpy.assign(scores.begin(), scores.end());
	//*/
	//
	//// iterator(순환 포인터역할)에 할당한다
	//vector<int>::iterator new_end = unique(sCpy.begin(), sCpy.end());
	//// 중복을 지운다    vector.erase(지우기 시작할 위치 바로전, 지우기 끝낼위치)
	//sCpy.erase(new_end, sCpy.end());
	////// vector1에 담긴 원소들의 표준 출력 스트림으로 출력
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
	// numeric_limits<데이터타입>::max()  데이터타입에서 최대 숫자 표시
	// cin.ignore(한번에 읽어들일 문자갯수, 읽어들인 뒤 입력할 문자)
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
 // 문자열을 tokenize 하여 vector에 넣기
vector<string> split_string(string input_string) {
	// vector 중복제거
	// iterator new_end에 unique 함수를 써서 중복되는 값을 제일 뒤에 쓰레기값으로 보낸다
	string::iterator new_end = unique(input_string.begin(), input_string.end(), [](const char &x, const char &y) {
		////////////////////////////////////////////////////[](const char &x, const char &y) 이건뭐지?
		// unique 한뒤 결과가 처음과 같다면 
		return x == y and x == ' ';
		//////////////////////////////////////////////////// 이렇게도 리턴할수있나?
	});
	// unique는 쓰레기값의 첫번째 인덱스(또는 반복자)를 반환한다
	// erase(지우기 시작할 위치, 지우기 마지막위치)함수로 쓰레기값지우기
	input_string.erase(new_end, input_string.end());

	// 문자열 뒤에 공백(' ')이 있으면 꺼낸다(string.pop_back())
	while (input_string[input_string.length() - 1] == ' ') {
		input_string.pop_back();
	}

	vector<string> splits;
	char delimiter = ' ';

	size_t i = 0;
	size_t pos = input_string.find(delimiter);

	while (pos != string::npos) {
		// 공백이 있을때까지(pos까지) splits에 복사(substr)하기
		splits.push_back(input_string.substr(i, pos - i));

		i = pos + 1;
		pos = input_string.find(delimiter, i);
	}
	// 마지막 token이 남았다!!
	// 마지막 token을 splits에 넣어주기
	splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));

	return splits;
}

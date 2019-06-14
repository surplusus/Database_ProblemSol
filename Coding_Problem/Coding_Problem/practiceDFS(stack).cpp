#include <iostream>
#include <vector>
#include <stack>
#include <utility>
#include <algorithm>
#include <string>
using namespace std;

typedef struct NODE {
	pair<int, int> coordinate;
	int path;
	NODE(int col, int row, int p) : coordinate(make_pair(col, row)), path(p) {}
};
int col[4] = { -1,1,0,0 };
int row[4] = { 0,0,1,-1 };
int vst[1001][1001] = { 0, };

void ClearVST(int nPick, const vector<vector<int> > & board);
int DFS(const vector<vector<int> > & board, int nPick);
int solution(vector<vector<int> > board);

int main()
{
	int size;
	cin >> size;
	while (!cin.get()) {}
	vector<vector<int> > board(size + 2, vector<int>(size + 2, 0));
	// board 입력받기
	// 양쪽에 0으로 벽을 만든다.
	string s;
	for (int i = 1; i < size + 1; i++)
	{
		getline(cin, s);
		if (tolower(s[0]) == 'q')
			break;
		int k = 1;
		for (int j = 0; j < s.size(); j++)
		{
			if (!isspace(s[j]))
			{
				board[i][k++] = s[j] - '0';
			}
		}
	}
	cout << solution(board) << endl;
	return 0;
}

// visit 행렬 초기화  
void ClearVST(int nPick, const vector<vector<int> > & board)
{
	const int boardSize = board.size();

	memset(vst, 0, sizeof(int) * 1001 * 1001);

	for (size_t i = 1; i < boardSize; i++)
		for (size_t j = 1; j < boardSize; j++)
		{
			vst[i][j] = -1;
			if (board[i][j] == nPick)
			{
				vst[i][j] = 1;
			}
		}
}

int DFS(const vector<vector<int> > & board, int nPick)
{
	const int boardSize = board.size();	// 뒤에 벽 있음
	stack<NODE> st;
	// board 바닥에 nPick과 같은 수가 있으면 모두 stack에 집어 넣고 path=1 적는다
	for (size_t i = 1; i < boardSize; i++)
		for (size_t j = 1; j < boardSize; j++)
		{
			vst[i][j] = -1;
			if (board[i][j] == nPick)
			{
				st.push(NODE(i, j, 1));
				vst[i][j] = 1;
			}
		}


	int result = -1;

	// 탐색 시작
	while (!st.empty())
	{
		NODE cur = st.top();
		do
		{
			cur = st.top();
			st.pop();
			int ccol = cur.coordinate.first;
			int crow = cur.coordinate.second;
			vst[ccol][crow] = 0;
			int path = cur.path;
			// 사방 탐색
			for (size_t i = 0; i < 4; i++)
			{
				int cc = ccol + col[i];
				int cr = crow + row[i];
				if (vst[cc][cr] == 1)
				{
					st.push(NODE(cc, cr, path + 1));
					
				}
			}

			result = result <= path ? path : result;
			
			// 제일 위에껄 봤더니 1이 있으면 처음에 넣었던 노드이니 visit 초기화.
		} while (cur.path != 1 && !st.empty());
		ClearVST(nPick, board);
	}

	result = (result == 1) ? -1 : result;
	return result;
}

int solution(vector<vector<int> > board)
{
	int answer = -1;
	for (size_t i = 1; i <= 4; i++)
	{
		if (answer < DFS(board, i))
			answer = DFS(board, i);
	}

	return answer;
}
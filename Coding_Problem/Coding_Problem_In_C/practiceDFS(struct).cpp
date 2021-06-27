#include <iostream>
#include <stack>
#include <vector>
//#include <memory>
using namespace std;

int dx[4] = { 0,-1,1,0 };
int dy[4] = {1, 0, 0, -1};

int nSize = 0;
typedef struct _Node
{
	int x, y;
	bool **visit;
	int path;
	// 입력받은 크기만큼 visit 메모리 할당
	void CreatVisitArray()
	{
		visit = new bool*[nSize];
		for (int i = 0; i < nSize; i++)
			visit[i] = new bool[nSize];
	}
	// 원소들을 입력받아 visit 0으로 초기화
	_Node(int _x, int _y, int _path) : x(_x), y(_y), path(_path)
	{
		CreatVisitArray();
		for (int i = 0; i < nSize; ++i)
			for (int j = 0; j < nSize; ++j)
				visit[i][j] = false;
	}
	// 다른 노드를 받아 visit 초기화
	_Node(const _Node & node) : x(node.x), y(node.y), path(node.path)
	{
		CreatVisitArray();
		for (int i = 0; i < nSize; ++i)
			for (int j = 0; j < nSize; ++j)
				visit[i][j] = node.visit[i][j];
	}

	~_Node()
	{
		for (int i = 0; i < nSize; ++i)
			delete[] visit[i];
		delete[] visit;
	}
}NODE;


int Solution(const vector<vector<int>> & board, int startX, int startY)
{
	// 시작 노드 객체 생성
	NODE startNode(startX, startY, 1);
	int startNumber = board[startY][startX];
	// 출력될 길이 초기화
	int maxDist = 1;
	stack<NODE> st;
	// 시작하는 장소에 visit 표시
	startNode.visit[startY][startX] = true;
	// 처음에 넣고 시작
	st.push(startNode);

	while (!st.empty())
	{
		// 처음 노드 curr에 기록하고 꺼낸다.
		NODE cur = st.top();
		int cX = cur.x;
		int cY = cur.y;
		st.pop();

		// 마지막 나올 결과를 뽑는부분
		maxDist = maxDist < cur.path ? cur.path : maxDist;

		// 4방향 검사
		for (int i = 0; i < 4; i++)
		{
			int nX = cX + dx[i];
			int nY = cY + dy[i];
			// 0보다 작거나, board크기보다 크면(경계포함) 안됨
			if (nX < 0 || nY < 0 || nX >= board.size() || nY >= board.size())
				continue;
			// board 숫자와 처음 바닥에 있던 숫자가 다르면 안됨
			if (startNumber != board[nY][nX])
				continue;
			// 방문한곳이면 안됨
			if (cur.visit[nY][nX] == true)
				continue;

			// 조건을 통과하면 이전 노드 복사하고
			NODE newNode(cur);
			// 방문 처리하고
			newNode.visit[nY][nX] = true;
			// 바닥에 전보다 +1 해서 적어놓고
			newNode.path = cur.path + 1;
			// 위치 반영하고
			newNode.x = nX;	newNode.y = nY;
			// 넣는다
			st.push(newNode);
		}
	}
	// 스택이 비면 빠져나와 결과 출력
	return maxDist;
}


int main()
{
	cin >> nSize;
	vector<vector<int>> board(nSize);

	for (int i = 0; i < nSize; i++)
	{
		for (int j = 0; j < nSize; j++)
		{
			int n; cin >> n;
			board[i].push_back(n);
		}
	}

	// solution (0,0)부터 마지막까지 순회
	int result = -1;
	for (int i = 0; i < nSize; i++)
	{
		int dist = 0;
		for (int j = 0; j < nSize; j++)
		{
			dist = Solution(board, j, i);
			result = result <= dist ? dist : result;
		}
	}


	if (result == 1)
		cout << -1 << endl;
	else
		cout << result << endl;
}
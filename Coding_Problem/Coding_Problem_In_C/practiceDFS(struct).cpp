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
	// �Է¹��� ũ�⸸ŭ visit �޸� �Ҵ�
	void CreatVisitArray()
	{
		visit = new bool*[nSize];
		for (int i = 0; i < nSize; i++)
			visit[i] = new bool[nSize];
	}
	// ���ҵ��� �Է¹޾� visit 0���� �ʱ�ȭ
	_Node(int _x, int _y, int _path) : x(_x), y(_y), path(_path)
	{
		CreatVisitArray();
		for (int i = 0; i < nSize; ++i)
			for (int j = 0; j < nSize; ++j)
				visit[i][j] = false;
	}
	// �ٸ� ��带 �޾� visit �ʱ�ȭ
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
	// ���� ��� ��ü ����
	NODE startNode(startX, startY, 1);
	int startNumber = board[startY][startX];
	// ��µ� ���� �ʱ�ȭ
	int maxDist = 1;
	stack<NODE> st;
	// �����ϴ� ��ҿ� visit ǥ��
	startNode.visit[startY][startX] = true;
	// ó���� �ְ� ����
	st.push(startNode);

	while (!st.empty())
	{
		// ó�� ��� curr�� ����ϰ� ������.
		NODE cur = st.top();
		int cX = cur.x;
		int cY = cur.y;
		st.pop();

		// ������ ���� ����� �̴ºκ�
		maxDist = maxDist < cur.path ? cur.path : maxDist;

		// 4���� �˻�
		for (int i = 0; i < 4; i++)
		{
			int nX = cX + dx[i];
			int nY = cY + dy[i];
			// 0���� �۰ų�, boardũ�⺸�� ũ��(�������) �ȵ�
			if (nX < 0 || nY < 0 || nX >= board.size() || nY >= board.size())
				continue;
			// board ���ڿ� ó�� �ٴڿ� �ִ� ���ڰ� �ٸ��� �ȵ�
			if (startNumber != board[nY][nX])
				continue;
			// �湮�Ѱ��̸� �ȵ�
			if (cur.visit[nY][nX] == true)
				continue;

			// ������ ����ϸ� ���� ��� �����ϰ�
			NODE newNode(cur);
			// �湮 ó���ϰ�
			newNode.visit[nY][nX] = true;
			// �ٴڿ� ������ +1 �ؼ� �������
			newNode.path = cur.path + 1;
			// ��ġ �ݿ��ϰ�
			newNode.x = nX;	newNode.y = nY;
			// �ִ´�
			st.push(newNode);
		}
	}
	// ������ ��� �������� ��� ���
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

	// solution (0,0)���� ���������� ��ȸ
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
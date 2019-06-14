#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

class MakeBoard
{
private:
	vector<vector<int>> data;
	vector<vector<bool>> vst;
	
public:
	explicit MakeBoard(istream & is)
	{
		int size;
		is >> size;
		data = vector<vector<int>>(size, vector<int>(size));
		vst = vector<vector<bool>>(size, vector<bool>(size));
		for (auto & row : data)		// 호성아 설명해줭
		{
			for (auto & col : row)
			{
				is >> col;
			}
		}
	}

	void FindPath()
	{
		int path = -2;
		for (int y = 0; y < data.size(); ++y)
		{
			for (int x = 0; x < data.size(); ++x)
				path = max(path, OptimizedPath(make_pair(x, y)));
		}
		
		if (path)
			cout << 1 + path << endl;
		else
			cout << -1 << endl;
	}

private:
	bool IsInArea(int x, int y) const
	{
		if (x < 0 || x >= data.size() || y < 0 || y >= data.size())
			return false;
		else
			return true;
	}

	int OptimizedPath(const pair<int, int> pos)
	{
		static int dx[] = { 0,-1,0,1 };
		static int dy[] = { 1,0,-1,0 };

		int cx = pos.first;
		int cy = pos.second;
		int path = 0;
		// 지나 왔으면 true
		vst[cy][cx] = true;
		for (int i = 0; i < 4; ++i)
		{
			int nx = cx + dx[i];
			int ny = cy + dy[i];
			if (IsInArea(nx, ny) && !vst[ny][nx] && data[cy][cx] == data[ny][nx])
				path = max(path, 1 + OptimizedPath(make_pair(nx, ny)));
		}
		vst[cy][cx] = false;
		return path;
	}
};

int main()
{
	MakeBoard board(cin);
	board.FindPath();

	return 0;
}
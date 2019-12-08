// HackerRank problem 
// Queue using Two Stacks
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

#include <stack>
void SwiftData(stack<int>* cursor, stack<int>* other)
{
	stack<int>* result = nullptr;
	while (cursor->empty())
	{
		other->push(cursor->top());
		cursor->pop();
	}
}
int main() {
	stack<int> in, out;
	int q, type, x;

	cin >> q;

	while (q--)
	{
		cin >> type;
		if (type == 1)
		{
			cin >> x;
			in.push(x);
		}
		else
		{
			if (out.empty())
			{
				while (!in.empty())
				{
					out.push(in.top());
					in.pop();
				}
			}

			if (type == 2)
				out.pop();
			if (type == 3)
			{
				if (out.empty())
					cout << "empty" << endl;
				else
					cout << out.top() << endl;
			}
		}

	}

	return 0;
}
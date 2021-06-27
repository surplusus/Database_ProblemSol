#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
#include <utility>
using namespace std;

class Solution {
public:
	void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
		vector<int> re = vector<int>(m + n);
		int idx1 = 0;
		int idx2 = 0;
		for (size_t i = 0; i < m + n; i++)
		{
			if (idx2 >= n)
			{
				re[i] = nums1[idx1++];
				continue;
			}
			else if (idx1 >= m)
			{
				re[i] = nums2[idx2++];
				continue;
			}

			if (nums1[idx1] < nums2[idx2])
				re[i] = nums1[idx1++];
			else if (nums1[idx1] > nums2[idx2])
				re[i] = nums2[idx2++];
			else
			{
				re[i++] = nums1[idx1++];
				re[i] = nums2[idx2++];
			}
		}
		nums1 = re;
	}
};

int main()
{
	Solution s;
	vector<int> n1 = vector<int>(4) = { 1, 3, 5, 7 };
	vector<int> n2 = vector<int>(4) = { 2,3,6,8,9,10};
	s.merge(n1, 4, n2, 6);
	for (size_t i = 0; i < n1.size(); i++)
	{
		cout << n1[i] << "/";
	}
	
	return 0;
}
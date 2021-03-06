#include <stdio.h>
#include <math.h>
int s_rows = 3;
int s_columns = 3;
int s2[3][3] = {
	{5,3,4},
	{1,5,8},
	{6,4,2}
};
int s4[3][3] = {	// 답은 18
	{6,1,2},
	{7,2,6},
	{5,6,2}
};
int s1[3][3] = {		// 답은 1
	{4,9,2},
	{3,5,7},
	{8,1,5}
};
int s3[3][3] = {		// 답은 4
	{4,8,2},
	{4,5,7},
	{6,1,6}
};
int s[3][3] = {		// 답은 17
	{6,7,8},
	{7,6,2},
	{3,2,3}
};
int func()
{
	int sum = 0;
	//  가운데는 5
	//sum = abs(s[1][1] - 5);
	
	// 모든 경우의 수
	int c[8][3][3] = {
		{{4,9,2},{3,5,7},{8,1,6}},
		{{8,3,4},{1,5,9},{6,7,2}},
		{{6,1,8},{7,5,3},{2,9,4}},
		{{2,7,6},{9,5,1},{4,3,8}},
		{{6,7,2},{1,5,9},{8,3,4}},
		{{8,1,6},{3,5,7},{4,9,2}},
		{{4,3,8},{9,5,1},{2,7,6}},
		{{2,9,4},{7,5,3},{6,1,8}},
	};
	int min = 99;
	for (int i = 0; i < 8; i++)
	{
		sum = 0;
		for (int j = 0; j < 3; j++)
		{
			for (int k = 0; k < 3; k++)
			{
				sum += abs(c[i][j][k] - s[j][k]);
			}
		}
		min = (min > sum) ? sum : min;
	}
	return min;
}

int main()
{
	int sum = func();
	printf("%d", sum);
	return 0;
}
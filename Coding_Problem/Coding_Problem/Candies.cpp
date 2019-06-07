// HackerRank problem 
// Candies
#include <iostream>
#include <vector>
using namespace std;

// Complete the candies function below.
long candies(int n, vector<int> arr) {
	long result = 0;
	int len = arr.size();
	vector<int> canBuk(n, 0);
	canBuk[0] = 1;	// 처음엔 무조건 1
	// 데이터가 1개일때
	if (len == 1)	return 1;

	// 왼쪽 -> 오른쪽
	for (size_t i = 1; i < len; i++)
	{
		// 왼쪽보다 크면 + 1
		if (arr[i] > arr[i - 1])
			canBuk[i] = canBuk[i - 1] + 1;
		// 왼쪽보다 작으면 걍 1
		else
			canBuk[i] = 1; 
	}
	// 제일 마지막

	// 왼쪽 <- 오른쪽
	for (int i = len - 1-1; i >= 0; --i)
	{
		// 오른쪽 값보다 크면 더한다
			if (arr[i] > arr[i + 1])
				// 오른쪽보다 왼쪽이 클때도 있음
				if (canBuk[i] < canBuk[i+1] +1)
					canBuk[i] = canBuk[i + 1] + 1;
	}
	// canbuk 모두 더함
	for (int i = 0; i < arr.size(); i++)
		result += canBuk[i];
	return result;
}

int main()
{

	int n;
	cin >> n;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	vector<int> arr(n);

	for (int i = 0; i < n; i++) {
		int arr_item;
		cin >> arr_item;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		arr[i] = arr_item;
	}

	long result = candies(n, arr);

	cout << result << "\n";

	return 0;
}

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
	canBuk[0] = 1;
	// 왼쪽 -> 오른쪽
	for (size_t i = 1; i < len-1; i++)
	{
		// 오른쪽보다 작다
		//	왼쪽도 작다
		if (arr[i - 1] > arr[i] && arr[i] < arr[i + 1])
			canBuk[i] = 1;
		// 왼쪽은 크다
		if (arr[i - 1] < arr[i] && arr[i] < arr[i + 1])
			canBuk[i] = canBuk[i - 1] + 1;

	}
	// 제일 마지막
	if (arr[len - 1] > arr[len - 2])
		arr[len - 1] = arr[len - 2] + 1;
	if (arr[len - 1] < arr[len - 2])
		arr[len - 1] = arr[len - 2] - 1;
	if (arr[len - 1] == arr[len - 2])
		arr[len - 1] = arr[len - 2];
	if (canBuk[len - 1 - 1] == 0)	//마지막전  bucket 0
		canBuk[len - 1] = 1;

	// 왼쪽 <- 오른쪽
	for (size_t i = len - 1 - 1; i > 0;i--)
	{
		// bucket이 0이면
		if (canBuk[i] == 0)
		{
			//오른쪽 보다 크다
			//왼쪽보다 작음(오른쪽보다 +1, 왼쪽은 알아서)
			if (arr[i] > arr[i + 1] && arr[i] < arr[i - 1])
				canBuk[i] = canBuk[i + 1] + 1;
			//왼쪽보다 큼(둘중 큰쪽보다 더 받음)
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
				canBuk[i] = (canBuk[i - 1] >= canBuk[i + 1] ? canBuk[i - 1] + 1 : canBuk[i + 1] + 1);
		}
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

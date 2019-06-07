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
	canBuk[0] = 1;	// ó���� ������ 1
	// �����Ͱ� 1���϶�
	if (len == 1)	return 1;

	// ���� -> ������
	for (size_t i = 1; i < len; i++)
	{
		// ���ʺ��� ũ�� + 1
		if (arr[i] > arr[i - 1])
			canBuk[i] = canBuk[i - 1] + 1;
		// ���ʺ��� ������ �� 1
		else
			canBuk[i] = 1; 
	}
	// ���� ������

	// ���� <- ������
	for (int i = len - 1-1; i >= 0; --i)
	{
		// ������ ������ ũ�� ���Ѵ�
			if (arr[i] > arr[i + 1])
				// �����ʺ��� ������ Ŭ���� ����
				if (canBuk[i] < canBuk[i+1] +1)
					canBuk[i] = canBuk[i + 1] + 1;
	}
	// canbuk ��� ����
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

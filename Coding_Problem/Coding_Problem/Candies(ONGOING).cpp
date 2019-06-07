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

	// ���� -> ������
	for (size_t i = 1; i < len; i++)
	{
		// �����ʺ��� ������
		if (arr[i] < arr[i + 1])
		{
			// ���ʺ��ٵ� �۴�
			if (arr[i - 1] > arr[i])
				canBuk[i] = 1;
			// ���ʺ��ٴ� ũ��
			if (arr[i - 1] < arr[i])
				canBuk[i] = canBuk[i - 1] + 1;
		}
		// �����ʺ��� ū ���
		else
			canBuk[i] = 1;
	}
	// ���� ������
	if (arr[len - 1] > arr[len - 2])
		arr[len - 1] = arr[len - 2] + 1;
	if (arr[len - 1] < arr[len - 2])
		arr[len - 1] = arr[len - 2] - 1;
	if (arr[len - 1] == arr[len - 2])
		arr[len - 1] = arr[len - 2];
	if (canBuk[len - 1 - 1] == 0)	//��������  bucket 0
		canBuk[len - 1] = 1;

	// ���� <- ������
	for (size_t i = len - 1 - 1; i > 0;i--)
	{
		// bucket�� 0�̸�
		if (canBuk[i] == 0)
		{
			//������ ���� ũ��
			//���ʺ��� ����(�����ʺ��� +1, ������ �˾Ƽ�)
			if (arr[i] > arr[i + 1] && arr[i] < arr[i - 1])
				canBuk[i] = canBuk[i + 1] + 1;
			//���ʺ��� ŭ(���� ū�ʺ��� �� ����)
			if (arr[i] > arr[i + 1] && arr[i] > arr[i - 1])
				canBuk[i] = (canBuk[i - 1] >= canBuk[i + 1] ? canBuk[i - 1] + 1 : canBuk[i + 1] + 1);
		}
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

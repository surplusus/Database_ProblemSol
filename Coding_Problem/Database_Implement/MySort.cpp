#include "MySort.h"
#include <ctime>

mysort::MyArr::MyArr()
{
	std::cout << "10俺楼府 扁夯 后 Array 积己\n";
	arr = new int[MAX_LEN_10] {0, };
	arrSize = MAX_LEN_10;
}

mysort::MyArr::MyArr(int _arrSize)
{
	arr = new int[_arrSize]{ 0, };
	arrSize = _arrSize;
	std::cout << _arrSize << "俺楼府 后 Array 积己\n";
}

mysort::MyArr::~MyArr()
{
	if (arr != nullptr)
	{
		std::cout << "瘤奎促\n";
		delete[] arr;
		arrSize = 0;
	}
}

void mysort::MyArr::SetMyArr(int _arrSize)
{
	if (arr != nullptr)
	{
		std::cout << "瘤快绊 ";
		delete[] arr;
		arrSize = 0;
	}
	arr = new int[_arrSize]{ 0, };
	arrSize = _arrSize;
	std::cout << _arrSize << "俺楼府 后 Array 积己\n";
}

std::ostream & mysort::operator<<(std::ostream & os, const MyArr & MA)
{
	for (int i = 0; i < MA.arrSize; i++)
		os << MA.arr[i] << " ";
	os << "\n";
	return os;
}

void mysort::BubbleSort(int arr[], int & arrSize)
{
	for (int i = 0; i < arrSize - 1; i++)
	{
		for (int j = 0; j < arrSize - (i-1); j++)
		{
			if (arr[j] > arr[j+1])
				std::swap(arr[j], arr[j + 1]);
		}
	}
}

void mysort::SelectionSort(int arr[], int & arrSize)
{
	int minIdx = 0;
	for (int i = 0; i < arrSize -1; i++)
	{
		minIdx = i;
		for (int j = i+1; j < arrSize; j++)
		{
			if (arr[minIdx] > arr[j])
				minIdx = j;
		}
		std::swap(arr[i], arr[minIdx]);
	}
}

void mysort::GenerateRanArr(int arr[], const int & arrSize)
{
	srand((unsigned int)time(NULL));
	for (int i = 0; i < arrSize; i++)
	{
		arr[i] = rand() % arrSize + 1;
		int cnt = i;
		while (--cnt>=0)
		{
			if (arr[i] == arr[cnt])
			{
				i--;
				break;
			}
		}
	}
}

void main()
{
	using namespace mysort;
	using std::cout;
	using std::endl;
	
	defArr.SetMyArr(20);
	cout << defArr;
	GenerateRanArr();
	cout << defArr;
	SelectionSort();
	cout << defArr;
}
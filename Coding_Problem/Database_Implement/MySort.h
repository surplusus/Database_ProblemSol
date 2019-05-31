#pragma once
#include <iostream>
namespace mysort {
	const int MAX_LEN_10 = 10;
	const int MAX_LEN_100 = 100;
	const int MAX_LEN_TEST = 1000000;

	class MyArr
	{
	public:
		int *arr;
		int arrSize;
		MyArr();
		MyArr(int _arrSize);
		~MyArr();
		void SetMyArr(int _arrSize);
		friend std::ostream & operator<< (std::ostream & os, const MyArr & MA);
	};

	MyArr defArr;
	// Sort
	void BubbleSort(int arr[] = defArr.arr, int & arrSize = defArr.arrSize);

	

	// Generator
	void GenerateRanArr(int arr[] = defArr.arr, const int & arrSize = defArr.arrSize);

}

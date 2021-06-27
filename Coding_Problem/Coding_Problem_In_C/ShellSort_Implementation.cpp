#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

// 기본 쉘정렬
void ShellSort_Basic(int a[], int n);
// 일반화된 쉘정렬
void ShellSort_Generalized(void *base, size_t nelem, size_t width, int(*fcmp)(const void*, const void*));

int main() {

	int arr[10] = { 6,8,4,2,5,9,1,3,7,0 };

	for (auto a : arr)
		std::cout << a << " ";
	std::cout << std::endl;

	ShellSort_Basic(arr, 10);

	for (auto a : arr)
		std::cout << a << " ";
	std::cout << std::endl;
}

void ShellSort_Basic(int a[], int n)
{
	// 크기가 n인 배열 a를 쉘 정렬하기
	int i, j, k, h, v;
	
	// h 값은 효율에 따라 달리 만들 수 있다. 
	// h 값은 보통 중위값, 평균값, 3h+1
	// 먼저 n 보다 작은 
	for (h = 1; h < n; h = 3 * h + 1);
	// h만큼 자른 범위 안에서 insertion sort한다
	for (h /= 3; h > 0; h /= 3)
	{
		for (i = 0; i < h; ++i)
		{
			// h 만큼 건너뛰어 있는 자료와 비교
			for (j = i + h; j < n; j += h)
			{
				// v : 건너뛰어 있는 자료 값
				v = a[j];
				// k : 건너뛰어 있는 자료 인덱스
				k = j;
				// k>h-1 : 인덱스가 마지막이 아니고
				// a[k-j]>v : 비교하는 자료 값이 h번째 이전 자료 보다 작으면
				// 인덱스의 값을 집어 들어서 (h만큼)이전 인덱스와 계속 비교하여 정렬될 때 까지 옮김
				// (자리 찾을때까지 미루는 느낌)
				while (k > h - 1 && a[k - h] > v)
				{
					// 값을 뒤로 옮기고
					a[k] = a[k - h];
					// 인덱스도 옮김
					k -= h;
				}
				// 자리를 찾았으면 (집어들었던) v에 들어있던 값을 넣음
				a[k] = v;
			}
		}
	}
}

void ShellSort_Generalized(void * base, size_t nelem, size_t width, int(*fcmp)(const void *, const void *))
{
	//base : 정렬할 배열, nelem : 배열 크기, width : 띄울 단격
	int i, j, k, h;
	void *v;
	v = malloc(width);

	for (h = 1; h < nelem; h = 3 * h + 1);

	for (h /= 3; h > 0; h /= 3)
	{
		for (i = 0; i < h; ++i)
		{
			for (j = i + h; j < nelem; j += h)
			{
				memcpy(v, (char*)base + j * width, width);
				k = j;
				while (k > h -1 && fcmp((char*)base + (k - h) * width, v) > 0)
				{
					memcpy((char*)base + k * width, (char*)base + (k - h) * width, width);
					k -= h;
				}
				memcpy((char*)base + k * width, v, width);
			}
		}
	}
	free(v);
}

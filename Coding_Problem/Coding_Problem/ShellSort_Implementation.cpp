#include <iostream>
#include <string>
#include <stdio.h>
#include <malloc.h>
#include <memory.h>

// �⺻ ������
void ShellSort_Basic(int a[], int n);
// �Ϲ�ȭ�� ������
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
	// ũ�Ⱑ n�� �迭 a�� �� �����ϱ�
	int i, j, k, h, v;
	
	// h ���� ȿ���� ���� �޸� ���� �� �ִ�. 
	// h ���� ���� ������, ��հ�, 3h+1
	// ���� n ���� ���� 
	for (h = 1; h < n; h = 3 * h + 1);
	// h��ŭ �ڸ� ���� �ȿ��� insertion sort�Ѵ�
	for (h /= 3; h > 0; h /= 3)
	{
		for (i = 0; i < h; ++i)
		{
			// h ��ŭ �ǳʶپ� �ִ� �ڷ�� ��
			for (j = i + h; j < n; j += h)
			{
				// v : �ǳʶپ� �ִ� �ڷ� ��
				v = a[j];
				// k : �ǳʶپ� �ִ� �ڷ� �ε���
				k = j;
				// k>h-1 : �ε����� �������� �ƴϰ�
				// a[k-j]>v : ���ϴ� �ڷ� ���� h��° ���� �ڷ� ���� ������
				// �ε����� ���� ���� �� (h��ŭ)���� �ε����� ��� ���Ͽ� ���ĵ� �� ���� �ű�
				// (�ڸ� ã�������� �̷�� ����)
				while (k > h - 1 && a[k - h] > v)
				{
					// ���� �ڷ� �ű��
					a[k] = a[k - h];
					// �ε����� �ű�
					k -= h;
				}
				// �ڸ��� ã������ (��������) v�� ����ִ� ���� ����
				a[k] = v;
			}
		}
	}
}

void ShellSort_Generalized(void * base, size_t nelem, size_t width, int(*fcmp)(const void *, const void *))
{
	//base : ������ �迭, nelem : �迭 ũ��, width : ��� �ܰ�
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

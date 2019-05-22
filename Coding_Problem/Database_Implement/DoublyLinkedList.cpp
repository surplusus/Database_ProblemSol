#include <iostream>
#include <string>
#include <fstream>
using namespace std;
typedef struct Node
{
	int data;
	Node *prev;
	Node *next;
}Node, *PNode;
typedef struct List
{
	PNode head;
	PNode tail;
	int size;
}List, *PList;
PList InitDLL(PList plist)
{
	plist->head = new Node;
	plist->tail = new Node;
	plist->head->data = 0;
	plist->tail->data = 0;
	plist->head->prev = plist->head;
	plist->head->next = plist->tail;
	plist->tail->next = plist->tail;
	plist->tail->prev = plist->head;
	plist->size = 0;
	return plist;
}
void InsertDLL(PList plist, int data)
{
	PNode newnode = new Node;
	if (plist->size == 0)
	{
		plist->head->next = newnode;
		plist->tail->prev = newnode;
		plist->size = 1;
		newnode->data = data;
		newnode->prev = plist->head;
		newnode->next = plist->tail;
	}
	else
	{
		PNode currnode = plist->head->next;
		for (int i = 0; i < plist->size; i++)
		{
			if (data < currnode->data)
			{
				if (currnode->prev == plist->head)
				{
					plist->head->next = newnode;
					newnode->prev = plist->head;
				}
				else
				{
					currnode->prev->next = newnode;
					newnode->prev = currnode->prev;
				}
				newnode->next = currnode;
				currnode->prev = newnode;
				newnode->data = data;
				plist->size++;
				return;
			}
			else if (data > currnode->data)
			{
				currnode = currnode->next;
			}
			else
			{
				cout << "������ �����Ͱ� �־� ������ �� �����ϴ�." << endl;
				delete newnode;
				return;
			}
		}
		currnode->prev->next = newnode;
		newnode->prev = currnode->prev;
		newnode->next = plist->tail;
		plist->tail->prev = newnode;
		newnode->data = data;
		plist->size++;
	}
}
void DeleteDLL(PList plist, int data)
{
	PNode currnode = plist->head->next;
	if (currnode == plist->tail)
	{
		cout << "�ڷᰡ �ƿ� �����ϴ�"<<endl;
		return;
	}
	for (int i = 0; i < plist->size; i++)
	{
		if (currnode->data == data)
		{
			plist->size--;
			currnode->prev->next = currnode->next;
			currnode->next->prev = currnode->prev;
			delete currnode;
			return;
		}
		currnode = currnode->next;
	}
	cout << "�׷� �ڷ� �����ϴ�" << endl;
}
void DeleteAllDLL(PList plist)
{
	PNode tmp = plist->head->next;
	while (tmp != plist->tail)
	{
		delete tmp->prev;
		tmp = tmp->next;
	}
	delete plist->tail->prev;
	delete plist->tail;
	delete plist;
}
void ReverseDLL(PList plist)
{
	/*
		head ���� ���(���� ���� �ִºκ�)���� �� head�� �տ� ���δ�
		currnode�� ���� ���� �����̸� �� �� �տ� ���δ�
		�������� currnode�� tail�� ���� ������, data�� �ִ� ������ ��� �տ� ���̰�
		head�� tail�� swap�Ѵ�
	*/
	PNode tmp;
	PNode currnode = plist->head->next;
	plist->head->next = plist->head;
	plist->head->prev = currnode;
	while (currnode != plist->tail)
	{
		tmp = currnode->next;
		currnode->next = currnode->prev;
		currnode->prev = tmp;
		currnode = currnode->prev;	// swap�����Ƿ� ���� ���� ���(next)�� ���� ���� ���(prev)�̴�
	}
	plist->tail->next = currnode->prev;
	plist->tail->prev = plist->tail;
	// �߰��� ��� �������� head�� tail�� ���� swap�Ѵ�
	tmp = plist->head;
	plist->head = plist->tail;
	plist->tail = tmp;
	
}
void PrintAllDLL(PList plist)
{
	PNode currnode = plist->head->next;
	for (int i = 0; i < plist->size; i++)
	{
		cout << currnode->data << endl;
		currnode = currnode->next;
	}
}
void OrderWithFileStream(PList plist, char f[])
{
	int ntmp;
	char ctmp[3];
	if (f[0] == 'r')
	{
		ReverseDLL(plist);
	}
	else if (f[0] == 'd')
	{
		ctmp[0] = f[2], ctmp[1] = f[3], ctmp[2] = f[4];
		ntmp = atoi(ctmp);
		DeleteDLL(plist, ntmp);
	}
	else if (f[0] == 'i')
	{
		ctmp[0] = f[2], ctmp[1] = f[3], ctmp[2] = f[4];
		ntmp = atoi(ctmp);
		InsertDLL(plist, ntmp);
	}
	else if (f[0] == 'p')
	{
		PrintAllDLL(plist);
	}
}
int main()
{
	// ����Ʈ �ʱ�ȭ
	PList plist = new List;
	plist = InitDLL(plist);
	// ���� �б�
	char inputString[120];
	ifstream inFile("data.txt");
	while (!inFile.eof())
	{
		inFile.getline(inputString, 100);
		OrderWithFileStream(plist, inputString);
	}
	inFile.close();
	return 0;
}
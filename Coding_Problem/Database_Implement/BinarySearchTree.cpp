#include <iostream>
using namespace std;

typedef struct Node {
	int data;
	Node *RChild;
	Node *LChild;
}Node, *PNode;

void InsertBT(PNode &pParent, int data)
{
	if (pParent == NULL)
	{
		PNode newNode = new Node;
		pParent = newNode;
		newNode->data = data;
		newNode->LChild = NULL;
		newNode->RChild = NULL;
	}
	else
	{
		PNode currNode = pParent;
		if (data < currNode->data)
		{
			if (currNode->LChild == NULL)
			{
				PNode newNode = new Node;
				newNode->data = data;
				newNode->LChild = NULL;
				newNode->RChild = NULL;
				currNode->LChild = newNode;
				return;
			}
			InsertBT(currNode->LChild, data);
		}
		else if (data > currNode->data)
		{
			if (currNode->RChild == NULL)
			{
				PNode newNode = new Node;
				newNode->data = data;
				newNode->LChild = NULL;
				newNode->RChild = NULL;
				currNode->RChild = newNode;
				return;
			}
			InsertBT(currNode->RChild, data);
		}
		else
		{
			cout << "���� ���� �ֽ��ϴ�. �Է��� ����մϴ�." << endl;
			return;
		}
	}
}
void DeleteBT(PNode pParent, int data)
{
	// ���ڷ� ������ ���
	PNode currNode = pParent;
	PNode replaceNode;
	PNode replaceNodeParent;
	// data�� ��忡 ����ִ� data ��
	// ������ Left Child�� �����
	// ũ�� Right Child�� �����
	if (currNode->data < data)
	{
		if (currNode->LChild == NULL)
		{
			cout << data << " �׷� �� ���׿�." << endl;
			return;
		}
		DeleteBT(currNode->LChild, data);
	}
	else if (currNode->data > data)
	{
		if (currNode->RChild == NULL)
		{
			cout << data << " �׷� �� ���׿�." << endl;
			return;
		}
		DeleteBT(currNode->RChild, data);
	}
	// data �´� ���� ã���� Left child �� ���� ū��(replaceNode)�� swap
	// left child�� ������ right child���� ���� ������(replaceNode)�� swap
	else
	{
		replaceNode = currNode;

		if (replaceNode->LChild != NULL)
		{
			replaceNodeParent = replaceNode;
			replaceNode = replaceNode->LChild;
			//���� ū replaceNode�� ���� ��
			while (replaceNode->RChild)
			{
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->RChild;
			}
			// data�� swap
			swap(replaceNode->data, currNode->data);
			cout << data << "�� �������" << endl;
			replaceNodeParent->LChild = replaceNode->LChild;
			delete replaceNode;
			replaceNode = NULL;
		}
		else if (replaceNode->RChild != NULL)
		{
			replaceNodeParent = replaceNode;
			replaceNode = replaceNode->RChild;
			//���� ���� replaceNode�� ���� ��
			while (replaceNode->LChild)
			{
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->LChild;
			}
			swap(replaceNode, currNode);
			cout << data << "�� �������" << endl;
			replaceNodeParent->RChild = replaceNode->RChild;
			delete replaceNode;
			replaceNode = NULL;
		}
		else
		{
			// �ڽĳ�尡 ���� replaceNode�� �׳� ����

			cout << data << "�� �������" << endl;

			delete replaceNode;
			replaceNode == NULL;
			return;
		}
	}
}
void SearchBT(const PNode pParent, int data)
{
	PNode currNode = pParent;
	while (true)
	{
		if (data < currNode->data)
		{
			if (currNode->LChild)
				currNode = currNode->LChild;
			else
			{
				cout << data << " �ڷᰡ ���׿�. ���俣" << endl;
				return;
			}
		}
		else if (data > currNode->data)
		{
			if (currNode->RChild)
				currNode = currNode->RChild;
			else
			{
				cout << data << " �ڷᰡ ���׿�. ���俣" << endl;
				return;
			}
		}
		else
		{
			cout << data << "�ڷ� ���� �ֳ׿�!" << endl;
			return;
		}

	}
}
void PrintBT(const PNode pParent)
{
	PNode currNode = pParent;
	if (currNode == NULL)
	{
		cout << "�ڷᰡ �����ϴ�" << endl;
		return;
	}
	if (currNode->LChild != NULL)
	{
		PrintBT(currNode->LChild);
	}
	cout << currNode->data << "  " << endl;
	if (currNode->RChild != NULL)
	{
		PrintBT(currNode->RChild);
	}
}
void DeleteAll(PNode pParent)
{
	PNode currNode = pParent;
	if (currNode == NULL)
	{
		cout << "�ڷᰡ �����ϴ�" << endl;
		return;
	}
	if (currNode->LChild != NULL)
	{
		DeleteAll(currNode->LChild);
	}
	if (currNode->RChild != NULL)
	{
		DeleteAll(currNode->RChild);
	}
	cout << currNode->data << " �� ����ϴ�" << endl;
	delete currNode;
}
int main()
{
	PNode proot = NULL; // root ���
	InsertBT(proot, 20);
	InsertBT(proot, 15);
	InsertBT(proot, 11);
	InsertBT(proot, 29);
	InsertBT(proot, 13);
	InsertBT(proot, 7);
	InsertBT(proot, 26);
	InsertBT(proot, 30);
	InsertBT(proot, 12);
	InsertBT(proot, 11);
	SearchBT(proot, 8);
	SearchBT(proot, 7);
	DeleteBT(proot, 26);
	DeleteBT(proot, 20);
	PrintBT(proot);
	DeleteAll(proot);

	return 0;
}
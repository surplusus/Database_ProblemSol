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
			cout << "같은 값이 있습니다. 입력을 취소합니다." << endl;
			return;
		}
	}
}
void DeleteBT(PNode pParent, int data)
{
	// 인자로 들어오는 노드
	PNode currNode = pParent;
	PNode replaceNode;
	PNode replaceNodeParent;
	// data와 노드에 들어있는 data 비교
	// 작으면 Left Child로 따라들어감
	// 크면 Right Child로 따라들어감
	if (currNode->data < data)
	{
		if (currNode->LChild == NULL)
		{
			cout << data << " 그런 값 없네요." << endl;
			return;
		}
		DeleteBT(currNode->LChild, data);
	}
	else if (currNode->data > data)
	{
		if (currNode->RChild == NULL)
		{
			cout << data << " 그런 값 없네요." << endl;
			return;
		}
		DeleteBT(currNode->RChild, data);
	}
	// data 맞는 것을 찾으면 Left child 의 가장 큰값(replaceNode)과 swap
	// left child가 없으면 right child에서 가장 작은값(replaceNode)과 swap
	else
	{
		replaceNode = currNode;

		if (replaceNode->LChild != NULL)
		{
			replaceNodeParent = replaceNode;
			replaceNode = replaceNode->LChild;
			//가장 큰 replaceNode로 따라 들어감
			while (replaceNode->RChild)
			{
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->RChild;
			}
			// data만 swap
			swap(replaceNode->data, currNode->data);
			cout << data << "를 지웠어요" << endl;
			replaceNodeParent->LChild = replaceNode->LChild;
			delete replaceNode;
			replaceNode = NULL;
		}
		else if (replaceNode->RChild != NULL)
		{
			replaceNodeParent = replaceNode;
			replaceNode = replaceNode->RChild;
			//가장 작은 replaceNode로 따라 들어감
			while (replaceNode->LChild)
			{
				replaceNodeParent = replaceNode;
				replaceNode = replaceNode->LChild;
			}
			swap(replaceNode, currNode);
			cout << data << "를 지웠어요" << endl;
			replaceNodeParent->RChild = replaceNode->RChild;
			delete replaceNode;
			replaceNode = NULL;
		}
		else
		{
			// 자식노드가 없는 replaceNode는 그냥 지움

			cout << data << "를 지웠어요" << endl;

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
				cout << data << " 자료가 없네요. 빠요엔" << endl;
				return;
			}
		}
		else if (data > currNode->data)
		{
			if (currNode->RChild)
				currNode = currNode->RChild;
			else
			{
				cout << data << " 자료가 없네요. 빠요엔" << endl;
				return;
			}
		}
		else
		{
			cout << data << "자료 여기 있네요!" << endl;
			return;
		}

	}
}
void PrintBT(const PNode pParent)
{
	PNode currNode = pParent;
	if (currNode == NULL)
	{
		cout << "자료가 없습니다" << endl;
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
		cout << "자료가 없습니다" << endl;
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
	cout << currNode->data << " 를 지웁니다" << endl;
	delete currNode;
}
int main()
{
	PNode proot = NULL; // root 노드
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
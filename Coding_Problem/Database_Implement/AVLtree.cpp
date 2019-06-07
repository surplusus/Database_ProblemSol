#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

typedef struct Node {
	int data;
	Node *RChild;
	Node *LChild;
	Node *Parent;
}Node, *PNode;

class AVL {
protected:
	PNode root;
public:
	AVL();
	AVL(int _data);
	~AVL();
	void Insert(int _data);
	void Search(int _data);
	void Delete(int _data);
	void Balancing();
private:
	void Insert(PNode & _curr, int _data);
	PNode Search(const PNode & _curr, int _data);
	void Delete(PNode & _curr, int _data);
	bool Balancing(PNode & _curr);
	int GetHeight(const PNode & _curr);
	friend istream & operator>>(istream & is, AVL & a);
	friend ostream & operator<<(ostream & os, const AVL & a);
};

int main()
{
	PNode root = new Node;


	delete root;
	return 0;
}

AVL::AVL()
{
	root = nullptr;
}

AVL::AVL(int _data)
{
	root = new Node;
	root->data = _data;
	root->LChild = nullptr;
	root->RChild = nullptr;
}

AVL::~AVL()
{
	if (root != nullptr)
		delete root;
}

void AVL::Insert(int _data)
{
	Insert(root, _data);
}

void AVL::Insert(PNode & _curr, int _data)
{
	if (_curr== nullptr)
	{
		AVL(_data);
	}
	else
	{
		if (_data < _curr->data)
		{
			if (_curr->LChild == nullptr)
			{
				PNode newNode = new Node;
				newNode->data = _data;
				newNode->LChild = NULL;
				newNode->RChild = NULL;
				newNode->Parent = _curr;
				_curr->LChild = newNode;
				return;
			}
			Insert(_curr->LChild, _data);
		}
		if (_data > _curr->data)
		{
			if (_curr->RChild == nullptr)
			{
				PNode newNode = new Node;
				newNode->data = _data;
				newNode->LChild = NULL;
				newNode->RChild = NULL;
				newNode->Parent = _curr;
				_curr->RChild = newNode;
				return;
			}
			Insert(_curr->RChild, _data);
		}
		else
		{
			cout << "���� ���� �ֽ��ϴ�. �Է��� ����մϴ�." << endl;
			return;
		}
	}
}

void AVL::Search(int _data)
{
	if (Search(root, _data))
		cout << "ã�ҵ�! " << _data << endl;
	else
		cout << _data << "��~��!" << endl;
}

PNode AVL::Search(const PNode & _curr, int _data)
{
	if (_data == _curr->data)
	{
		return _curr;
	}
	else if (_data < _curr->data)
	{
		Search(_curr->LChild, _data);
	}
	else if (_data > _curr->data)
	{
		Search(_curr->RChild, _data);
	}
	return nullptr;
}

void AVL::Balancing()
{
	if (!Balancing(root))
	{
		cout << "�ڷᰡ �����ϴ�" << endl;
		return;
	}
}
bool AVL::Balancing(PNode & _curr)
{
	PNode curr = _curr;
	// curr�� ���� ������ root�� ���� ���°�
	if (curr == nullptr)
		return false;
	// curr�� �θ�� ����
	else if (curr->LChild != nullptr)
		Balancing(curr->LChild);
	if (curr->RChild != nullptr)
		Balancing(curr->RChild);

	// �ұ�Ģ�ΰ� Ȯ��
	int balFactor = GetHeight(curr->LChild) - GetHeight(curr->RChild);
	if (balFactor == -2)
	{
		PNode tmp;
		//LLrotation
		curr->Parent = tmp;
		tmp = curr->LChild;
		curr->LChild = tmp->RChild;
		tmp->RChild = curr;
		//LRrotation (�Լ��� �����غ���)

	}
	if (balFactor == 2)
	{
		PNode tmp;
		//RLrotation

		//RRrotation 
		if (curr->Parent->LChild->data == curr->data)
			curr->Parent->LChild = tmp;
		if (curr->Parent->RChild->data == curr->data)
			curr->Parent->RChild = tmp;
		tmp = curr->RChild;
		curr->RChild = tmp->LChild;
		tmp->LChild = curr;
	}
}

int AVL::GetHeight(const PNode & _curr)
{
	int hgt = 0;
	if (_curr)
	{
		int left = GetHeight(_curr->LChild);
		int right = GetHeight(_curr->RChild);
		int nMax = max(left, right);
		hgt = nMax + 1;
	}
	return hgt;
}

istream & operator>>(istream & is, AVL & a)
{
	int data;
	is >> data;
	a.Insert(data);
	return is;
}

ostream & operator<<(ostream & os, const AVL & a)
{
	cout << "�� ���� ����Ÿ ���" << endl;
	
	cout << "���ĵ� ������ ���" << endl;
}
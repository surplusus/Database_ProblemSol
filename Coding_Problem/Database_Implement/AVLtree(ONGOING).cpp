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
private:
	void Insert(PNode & _curr, PNode & parent, int _data);
	PNode Search(const PNode & _curr, int _data);
	void Delete(PNode & _curr, int _data);
	bool Balancing(PNode & _curr);
	int GetHeight(const PNode & _curr) const;
	int DiffHeight(const PNode & _curr) const;
	void LLRotation(PNode & _curr);
	void RRRotation(PNode & _curr);
	void LRRotation(PNode & _curr);
	void RLRotation(PNode & _curr);
	friend istream & operator>>(istream & is, AVL & a);
	friend ostream & operator<<(ostream & os, const AVL & a);
};

int main()
{
	AVL p;
	p.Insert(5);
	p.Insert(7);
	p.Insert(2);
	p.Insert(4);
	p.Insert(1);
	p.Insert(9);

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
	root->Parent = nullptr;
}

AVL::~AVL()
{
	if (root != nullptr)
		delete root;
}

void AVL::Insert(int _data)
{
	PNode n = nullptr;
	Insert(root, n, _data);
}

void AVL::Insert(PNode & _curr, PNode & _parent, int _data)
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
				// �θ� ����? (�����Ǻ�)
				if (GetHeight(_curr) - GetHeight(_parent->RChild) > 1)
					// RR or RL
					Balancing(_curr);
				return;
			}
			Insert(_curr->LChild, _curr, _data);
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
				// �θ� ����? 
				if (GetHeight(_parent->LChild) - GetHeight(_curr) < -1)
					// LL or LR
					Balancing(_curr);
				return;
			}
			Insert(_curr->RChild, _curr, _data);
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
		cout << _data << " ��~��!" << endl;
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

//bool AVL::Balancing(PNode & curr)
//{
//	// �ұ�Ģ�ΰ� Ȯ��
//	int balFactor = GetHeight(curr->LChild) - GetHeight(curr->RChild);
//	if (balFactor == -2)
//	{
//		//`
//		PNode tmp;
//		//LLrotation
//		curr->Parent = tmp;
//		tmp = curr->LChild;
//		curr->LChild = tmp->RChild;
//		tmp->RChild = curr;
//		//LRrotation (�Լ��� �����غ���)
//
//	}
//	if (balFactor == 2)
//	{
//		PNode tmp;
//		//RLrotation
//
//		//RRrotation 
//		if (curr->Parent->LChild->data == curr->data)
//			curr->Parent->LChild = tmp;
//		if (curr->Parent->RChild->data == curr->data)
//			curr->Parent->RChild = tmp;
//		tmp = curr->RChild;
//		curr->RChild = tmp->LChild;
//		tmp->LChild = curr;
//	}
//}

bool AVL::Balancing(PNode & curr)
{
	int factor = DiffHeight(curr);
	// ���� ����Ʈ�������� ������ �Ǿ� ������ ���� ��� 
	if (factor > 1)
	{
		// �� ���� �ڽ� ������ ����
		if (DiffHeight(curr->LChild) > 0)
		{
			LLRotation(curr);
		}
		// �� ������ �ڽ� ������ ���� 
		else
		{
			LRRotation(curr);
		}
	}
	else if (factor < -1)
	{
		if (DiffHeight(curr->RChild) > 0)
		{
			//temp = rl(temp);
			RLRotation(curr);
		}
		else
		{
			RRRotation(curr);
		}
	}
}
int AVL::GetHeight(const PNode & _curr) const
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

int AVL::DiffHeight(const PNode & _curr) const
{
	int diff = GetHeight(_curr->LChild) - GetHeight(_curr->RChild);
	return diff;
}

void AVL::LLRotation(PNode & _curr)
{
	PNode tmp;
	// �θ��� ���� �ڽ��ΰ�? ������ �ڽ��ΰ�?
	if (_curr->Parent->LChild == _curr)
		_curr->Parent->LChild = tmp;
	if (_curr->Parent->RChild == _curr)
		_curr->Parent->RChild = tmp;

	tmp = _curr->LChild;
	_curr->LChild = tmp->RChild;
	_curr->LChild->Parent = _curr;
	tmp->RChild = _curr;
	_curr->Parent = tmp;
}
void AVL::RRRotation(PNode & _curr)
{
	PNode tmp;
	// �θ��� ���� �ڽ��ΰ�? ������ �ڽ��ΰ�?
	if (_curr->Parent->LChild == _curr)
		_curr->Parent->LChild = tmp;
	if (_curr->Parent->RChild == _curr)
		_curr->Parent->RChild = tmp;
	
	tmp = _curr->RChild;
	_curr->RChild = tmp->LChild;
	_curr->RChild->Parent = _curr;
	tmp->LChild = _curr;
	_curr->Parent = tmp;
}
void AVL::LRRotation(PNode & _curr)
{
	// curr�� �����ؼ� 
	PNode tmp = _curr;
	// ���纻�� curr�� ������ ���̿� �ް�
	_curr->RChild = tmp;
	// curr�����ڽ��� ������ �ڽ� ���� �θ� ���� �ְ�
	_curr->data = _curr->LChild->RChild->data;
	// curr�� ������ �ڽ��� ���� �ڽ��� tmp�� �־��ٰ�
	tmp = _curr->LChild->RChild->LChild;
	// ���� curr�� ������ �ڽ��� �����
	delete _curr->LChild->RChild;
	// tmp ��带 curr�� �����ʿ� ���δ�
	_curr->LChild = tmp;
}
void AVL::RLRotation(PNode & _curr)
{
	// curr�� �����ؼ� 
	PNode tmp = _curr;
	// ���纻�� curr�� ������ ���̿� �ް�
	_curr->LChild = tmp;
	// curr�����ڽ��� ������ �ڽ� ���� �θ� ���� �ְ�
	_curr->data = _curr->RChild->LChild->data;
	// curr�� ������ �ڽ��� ���� �ڽ��� tmp�� �־��ٰ�
	tmp = _curr->RChild->LChild->RChild;
	// ���� curr�� ������ �ڽ��� �����
	delete _curr->RChild->LChild;
	// tmp ��带 curr�� �����ʿ� ���δ�
	_curr->RChild = tmp;

	/*
	PNode temp;
	LLRotation(_curr->RChild);
	RRRotation(_curr);
	*/
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
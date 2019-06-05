// 2���� vector�� hashtable�� ������
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// hash��
typedef struct _HASH
{
	int hashcode;
	string data;
}Hash, *PHash;
// 2���� vector
vector<vector<PHash>> HashTable(27);

int GetHashCode(string key);
int ConvertToIdx(int hashcode);
void Insert();
void Delete();
bool Search(string key);
void FSearch();
void PrintHash();
void Interface();

int main()
{
	Interface();
}

// key ���� ù��° ���ڸ� hashcode�� �����
int GetHashCode(string key)
{
	return key[0];
}

int ConvertToIdx(int hashcode)
{
	return (hashcode - 'A') % 27;
}

void Insert()
{

	// ���ο� hash�� ���� �Ҵ�
	PHash newhash = new Hash;
	cout << "(����� 0)key ���� �Է� : ";
	string key;
	cin >> key;
	if (key[0] == '0')
		Interface();
	newhash->data = key;
	// key ���� �������� hashcode�� ����� (GetHashCode())
	newhash->hashcode = GetHashCode(key);
	
	// hashcode�� index�� ��´�
	int index = ConvertToIdx(newhash->hashcode);

	// index�� ���缭 ������ hash�� ���� push_back()
	HashTable[index].push_back(newhash);
	cout << key << "�� " << index << "�� index�� �־����ϴ�" << endl;

	Insert();
}

void Delete()
{
	cout << "���� ���� �Է� : ";
	string key;
	cin >> key;
	if (Search(key))
	{
		int index = ConvertToIdx(GetHashCode(key));
		int len = HashTable[index].size();
		for (size_t i = 0; i < len; i++)
		{
			if (HashTable[index][i]->data == key)
			{
				swap(HashTable[index][i], HashTable[index][len - 1]);
				HashTable[index].pop_back();
				cout << key << " ���� �������ϴ�." << endl;
				return;
			}
		}
	}
	Interface();
}

bool Search(string key)
{
	// key ������ hashcode ã�� index�� ��ȯ
	PHash foundVal;
	int index = ConvertToIdx(GetHashCode(key));
	int len = HashTable[index].size();
	for (size_t i = 0; i < len; i++)
	{
		if (HashTable[index][i]->data == key)
		{
			cout << key << ", ã�Ҵ�! ���! : " << index<< endl;
			return true;
		}
	}
	cout << key << "�� ��ȿ���� �ʽ��ϴ�." << endl;
	return false;
}

void FSearch()
{
	string key;
	cout << "ã�� key �� �Է� : ";
	cin >> key;
	Search(key);
	Interface();
}

void PrintHash()
{
	cout << "����� �� �Է� : ";
	string key;
	cin >> key;
	cout << "key �� �ȿ� ����ִ� ���ĵ� data" << endl;
	// �ԷµǴ� key���� ù���� ���ڰ� ���� hash ��� ���
	int index = ConvertToIdx(GetHashCode(key));
	int len = HashTable[index].size();
	// string �� (key.compare(b) < 0) : key�� b���� ���������� ��
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (HashTable[index][i]->data.compare(HashTable[index][j]->data) > 0)
				swap(HashTable[index][i], HashTable[index][j]);
		}
	}
	// ���� index �� print
	for (int i = 0; i < len; i++)
	{
		cout << HashTable[index][i]->data << endl;
	}
	Interface();
}

void Interface()
{
	cout << "	[0] Insert" << endl;
	cout << "	[1] Search" << endl;
	cout << "	[2] Delete" << endl;
	cout << "	[3] PrintHash" << endl;
	cout << "	[4] Exit" << endl;
	cout << "���ڸ� �Է��ϼ��� : ";

	int n;
	cin >> n;

	switch (n)
	{
	case 0:
		Insert();
	case 1:
		FSearch();
	case 2:
		Delete();
	case 3:
		PrintHash();
	case 4:
		return;
	default:
		break;
	}
}

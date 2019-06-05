// 2차원 vector로 hashtable을 만들어보자
#include <iostream>
#include <string>
#include <vector>
using namespace std;
// hash값
typedef struct _HASH
{
	int hashcode;
	string data;
}Hash, *PHash;
// 2차원 vector
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

// key 값의 첫번째 글자를 hashcode로 만든다
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

	// 새로운 hash를 동적 할당
	PHash newhash = new Hash;
	cout << "(종료는 0)key 값을 입력 : ";
	string key;
	cin >> key;
	if (key[0] == '0')
		Interface();
	newhash->data = key;
	// key 값을 기준으로 hashcode를 만든다 (GetHashCode())
	newhash->hashcode = GetHashCode(key);
	
	// hashcode로 index를 얻는다
	int index = ConvertToIdx(newhash->hashcode);

	// index에 맞춰서 생성된 hash를 연결 push_back()
	HashTable[index].push_back(newhash);
	cout << key << "를 " << index << "번 index에 넣었습니다" << endl;

	Insert();
}

void Delete()
{
	cout << "지울 값을 입력 : ";
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
				cout << key << " 값을 지웠습니다." << endl;
				return;
			}
		}
	}
	Interface();
}

bool Search(string key)
{
	// key 값으로 hashcode 찾고 index로 반환
	PHash foundVal;
	int index = ConvertToIdx(GetHashCode(key));
	int len = HashTable[index].size();
	for (size_t i = 0; i < len; i++)
	{
		if (HashTable[index][i]->data == key)
		{
			cout << key << ", 찾았다! 요놈! : " << index<< endl;
			return true;
		}
	}
	cout << key << "는 유효하지 않습니다." << endl;
	return false;
}

void FSearch()
{
	string key;
	cout << "찾을 key 값 입력 : ";
	cin >> key;
	Search(key);
	Interface();
}

void PrintHash()
{
	cout << "출력할 값 입력 : ";
	string key;
	cin >> key;
	cout << "key 값 안에 들어있는 정렬된 data" << endl;
	// 입력되는 key에서 첫번재 글자가 같은 hash 모두 출력
	int index = ConvertToIdx(GetHashCode(key));
	int len = HashTable[index].size();
	// string 비교 (key.compare(b) < 0) : key가 b보다 사전순으로 앞
	for (int i = 0; i < len-1; i++)
	{
		for (int j = i+1; j < len; j++)
		{
			if (HashTable[index][i]->data.compare(HashTable[index][j]->data) > 0)
				swap(HashTable[index][i], HashTable[index][j]);
		}
	}
	// 같은 index 값 print
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
	cout << "숫자를 입력하세요 : ";

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

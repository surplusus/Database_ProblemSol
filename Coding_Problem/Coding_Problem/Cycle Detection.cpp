// HackerRank problem 
// Caeser Cipher

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class SinglyLinkedListNode {
public:
	int data;
	SinglyLinkedListNode* next;

	SinglyLinkedListNode(int node_data) {
		this->data = node_data;
		this->next = nullptr;
	}
};

class SinglyLinkedList {
public:
	SinglyLinkedListNode* head;
	SinglyLinkedListNode* tail;

	SinglyLinkedList() {
		this->head = nullptr;
		this->tail = nullptr;
	}

	void insert_node(int node_data) {
		SinglyLinkedListNode* node = new SinglyLinkedListNode(node_data);

		if (!this->head) {
			this->head = node;
		}
		else {
			this->tail->next = node;
		}

		this->tail = node;
	}
};

void print_singly_linked_list(SinglyLinkedListNode* node, string sep, ofstream& fout) {
	while (node) {
		fout << node->data;

		node = node->next;

		if (node) {
			fout << sep;
		}
	}
}

void free_singly_linked_list(SinglyLinkedListNode* node) {
	while (node) {
		SinglyLinkedListNode* temp = node;
		node = node->next;

		free(temp);
	}
}

// 나은 방법
//bool has_cycle(SinglyLinkedListNode* head) {
//	map<size_t, bool> visit;
//	if (head->next == nullptr)
//		return false;
//	while (head->next != nullptr)
//	{
//		if (visit.find(reinterpret_cast<size_t>(head)) == visit.end())
//		{
//			visit.insert(make_pair(reinterpret_cast<size_t>(head), true));
//		}
//		else
//			return true;
//
//		head = head->next;
//	}
//	return false;
//}

int main()
{
	int tests;
	cin >> tests;
	cin.ignore(numeric_limits<streamsize>::max(), '\n');

	for (int tests_itr = 0; tests_itr < tests; tests_itr++) {
		int index;
		cin >> index;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		SinglyLinkedList* llist = new SinglyLinkedList();

		int llist_count;
		cin >> llist_count;
		cin.ignore(numeric_limits<streamsize>::max(), '\n');

		for (int i = 0; i < llist_count; i++) {
			int llist_item;
			cin >> llist_item;
			cin.ignore(numeric_limits<streamsize>::max(), '\n');

			llist->insert_node(llist_item);
		}

		SinglyLinkedListNode* extra = new SinglyLinkedListNode(-1);
		SinglyLinkedListNode* temp = llist->head;

		for (int i = 0; i < llist_count; i++) {
			if (i == index) {
				extra = temp;
			}

			if (i != llist_count - 1) {
				temp = temp->next;
			}
		}

		temp->next = extra;

		bool result = has_cycle(llist->head);

		cout << result << "\n";
	}

	return 0;
}
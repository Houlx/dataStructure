#include <iostream>
using namespace std;
class Node {
public:
	int data[5];
	int number;
	Node* next;
	Node(Node* nextPtr = NULL, int num = 0) {
		for (int i = 0; i < 5; i++) {
			data[i] = 0;
		}
		next = nextPtr;
		number = num;
	}
	Node(int* data, Node* nextPtr = NULL, int num = 0) {
		next = nextPtr;
		for (int i = 0; i < 5; i++) {
			this->data[i] = data[i];
		}
		number = num;
	}
	int search(int key) {
		for (int i = 0; i < 5; i++) {
			if (data[i] == key) {
				return i;
			}
		}
		return -1;
	}
	int getNumber() {
		return number;
	}
};

class List {
private:
	Node* head;
	Node* tail;
	int count;
public:
	List() {
		head = NULL;
		tail = NULL;
		count = 0;
	}
	void append(int* data) {
		count++;
		Node *node = new Node(data, NULL, count);
		if (!head)
		{
			head = node;
			tail = node;
		}
		else {
			tail->next = node;
			tail = node;
		}
	}
	Node* search(int key, int& index) {
		Node* p = head;
		while (p->next) {
			if (p->search(key) != -1) {
				index = p->search(key);
				return p;
			}
			p = p->next;
		}
		if (p->search(key) != -1) {
			index = p->search(key);
			return p;
		}
		return NULL;
	}
};

int main() {
	List list;

	int data1[] = { 1,2,3,4,5 };
	int data2[] = { 42,48,89,66,33 };
	int data3[] = { 45,56,76,87,23 };

	list.append(data1);
	list.append(data2);
	list.append(data3);

	int index = 0;
	Node* pointer = list.search(66, index);
	cout << "node number " << pointer->getNumber() << endl << "index " << index << endl;
}
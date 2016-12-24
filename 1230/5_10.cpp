#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random(int x) {
	return (rand() % x) + 1;
}

class Node {
	friend class List;
private:
	int data;
	int index;
	Node* next;
public:
	Node(int data, int index, Node* next = NULL) {
		this->data = data;
		this->index = index;
		this->next = next;
	}

};

class List {
private:
	Node* head;
	Node* tail;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	List(int data[], int n) {
		head = NULL;
		tail = NULL;
		for (int i = 0; i < n; i++) {
			insert(data[i], i);
		}
	}
	void insert(int data, int index) {
		Node *node = new Node(data, index);
		if (!head)
		{
			head = node;
			tail = node;
		}
		else {
			Node* temp = head;
			if (node->data < temp->data) {
				node->next = head;
				head = node;
			}
			while (temp->next) {
				if ((node->data > temp->data) && (node->data < temp->next->data)) {
					node->next = temp->next;
					temp->next = node;
				}
				temp = temp->next;
			}
			if (node->data > temp->data) {
				temp->next = node;
				node->next = NULL;
			}
		}
		Node* p = head;
		while (p->next) {
			p = p->next;
		}
		tail = p;
	}

	void printData() {
		Node* p = head;
		while (p->next) {
			cout << p->data << " ";
			p = p->next;
		}
		cout << p->data;
	}

	void printIndex() {
		Node* p = head;
		while (p->next) {
			cout << p->index << " ";
			p = p->next;
		}
		cout << p->index;
	}

	void print() {
		Node* p = head;
		while (p->next) {
			cout << p->data << "-" << p->index << " ";
			p = p->next;
		}
		cout << p->data << "-" << p->index;
	}
};



int main() {
	srand((int)time(0));

	int data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = random(100);
		cout << data[i] << " ";
	}
	cout << endl;

	List list(data,10);

	list.print();
	cout << endl;
	return 0;
}
#include <iostream>
using namespace std;

class Node {
public:
	int data;
	Node* next;
public:
	Node(const int& a, Node* nextPtr = NULL) {
		data = a;
		next = nextPtr;
	}
};

class List {
public:
	Node* head;
	Node* tail;

	int number;
public:
	List() {
		head = NULL;
		tail = NULL;
	}
	void append(int data) {
		Node* node = new Node(data);
		if (!head)
		{
			head = node;
			tail = node;
			number++;
		} else {
			tail->next = node;
			tail = node;
			number++;
		}
	}

	//求链表中的最大值
	int findMax(Node*);
	// Node* getMax();
	//求节点个数
	int count(Node*);
	//求所有整数平均值
	double average(Node*,int);
};

int List::count(Node* head) {
	if (!head)
	{
		return 0;
	}else{
		return 1+count(head->next);
	}
}
int List::findMax(Node* head) {
	if (!head->next)
	{
		return head->data;
	}else{
		int temp=findMax(head->next);
		return head->data>temp?head->data:temp;
	}
}

double List::average(Node* head,int length) {
	if (!head->next)
	{
		return ((double)head->data)/length;
	}else{
		double temp=average(head->next,length);
		return temp+(double)head->data/length;
	}
}

int main(int argc, char const *argv[])
{
	List *list = new List();
	list->append(2);
	list->append(2);
	list->append(3);
	list->append(1);
	list->append(7);
	list->append(5);

	cout << list->count(list->head) << endl;
	cout << list->findMax(list->head) << endl;
	cout << list->average(list->head,list->count(list->head)) << endl;

	return 0;
}
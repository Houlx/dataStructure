#include <iostream>
using namespace std;

//给定一个不带头节点的单链表，写出将链表倒置的方法
class Node
{
public:
	int data;
	Node* next;
public:
	Node(const int& a,Node* nextPtr=NULL){
		data=a;
		next=nextPtr;
	}
};

class List{
private:
	Node* head;
	Node* tail;

	int number;
public:
	List(){
		head=NULL;
		tail=NULL;

		number=0;
	}
	void append(int data){
		Node* node=new Node(data);
		if (!head)
		{
			head=node;
			tail=node;
			number++;
		}
		else{
			tail->next=node;
			tail=node;
			number++;
		}
	}
	int length(){
		return number;
	}
	~List(){
		Node* temp=NULL;
		while(head->next){
			temp=head->next;
			delete head;
			head=temp;
		}
		delete head;
	}

	void print(){
		Node* p=head;
		while(p->next){
			cout<<p->data<<endl;
			p=p->next;
		}
		cout<<p->data<<endl;
	}

	void reverse();
};

void List::reverse(){
	Node *p,*q;
	p=head;
	head=NULL;
	while(p!=NULL){
		q=p;
		p=p->next;
		q->next=head;
		head=q;
	}
}

int main(int argc, char const *argv[])
{
	List *list = new List();
	list->append(2);
	list->append(3);
	list->append(1);
	list->append(7);
	list->append(5);

	list->print();

	list->reverse();

	list->print();
	return 0;
}
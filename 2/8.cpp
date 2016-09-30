#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Node {
private:
	
public:
	int data;
	Node* next;
	Node* prev;

	Node(int data,Node* next=NULL,Node* prev=NULL){
		this->data=data;
		this->prev=prev;
		this->next=next;
	}

	Node(Node* next=NULL,Node* prev=NULL){
		this->data=0;
		this->next=next;
		this->prev=prev;
	}
};

class List
{
private:
	Node* head;
	Node* tail;
	int number;
public:
	List(){
		Node* headNode=new Node();
		head=headNode;
		tail=headNode;
		head->prev=tail;
		tail->next=head;
		number=0;
	}

	void append(int data){
		Node* newNode=new Node(data);
		newNode->prev=tail;
		newNode->next=tail->next;
		tail->next=newNode;
		newNode->next->prev=tail->next;
		tail=newNode;
		number++;
	}
	~List();
	void print(){
		for(Node* p=head->next;p!=head;p=p->next){
			cout<<p->data<<endl;
		}
	}

	void deleteValueX(int x);
};

void List::deleteValueX(int x){
	for(Node* p=head->next;p!=head;p=p->next){
		if (p->data==x)
		{
			p->prev->next=p->next;
			p->next->prev=p->prev;
			p->next=NULL;
			p->prev=NULL;
			delete p;
			break;
		}
	}
}

int main(int argc, char const *argv[]){
	List* list=new List();
	for (int i = 0; i < 10; ++i)
	{
		list->append(i+1);
	}
	list->append(4);

	list->deleteValueX(4);
	list->print();
	return 0;
}
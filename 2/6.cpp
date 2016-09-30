#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

class Node {
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
		head=new Node(0);
		tail=head;
		number=0;
	}

	void append(int data){
		Node* node=new Node(data);
		tail->next=node;
		tail=node;
		number++;
	}

	void print(){
		for (int i = 0; i < length(); ++i)
		{
			cout<<getPosition(i)->data<<endl;
		}
	}

	Node* getPosition(int index){
		if (index==-1)
		{
			return head;
		}
		int count=0;
		Node* p=head->next;
		while(p&&count<index){
			p=p->next;
			count++;
		}
		return p;
	}

	bool insert(const int position,int data){
		Node *p,*q;
		if ((p=getPosition(position-1))==NULL)
		{
			cout<<"error"<<endl;
			return false;
		}

		q=new Node(data,p->next);
		p->next=q;
		if (p==tail)
		{
			tail=q;
		}
		number++;
		return true;
	}
	~List(){
		Node* p=head;
		Node* q;
		while(p){
			q=p;
			p=p->next;
			delete q;
		}
	}

	int length(){
		return number;
	}

	void merge(List*);
};



void List::merge(List* list){
	for (int i = 0; i < list->length(); ++i)
	{
		for (int j = 0; j < this->length(); ++j)
		{
			if (list->getPosition(i)->data>this->getPosition(j)->data&&this->getPosition(j+1))
			{
				if (list->getPosition(i)->data<this->getPosition(j+1)->data)
				{
					this->insert(j+1,list->getPosition(i)->data);
					break;
				}
			}
			if (list->getPosition(i)->data>this->getPosition(j)->data&&!this->getPosition(j+1))
			{
				this->insert(j+1,list->getPosition(i)->data);
				break;
			}
			if (list->getPosition(i)->data<this->getPosition(j)->data)
			{
				this->insert(j,list->getPosition(i)->data);
				break;
			}
		}
	}
}
int main(int argc, char const *argv[]){
	List* ha=new List();
	List* hb=new List();

	ha->append(1);
	ha->append(1);
	ha->append(3);
	ha->append(5);
	ha->append(6);

	hb->append(0);
	hb->append(2);
	hb->append(3);
	hb->append(4);
	hb->append(7);

	// ha->print();
	// cout<<endl<<endl;
	// hb->print();

	ha->merge(hb);
	// ha->insert(3,67);
	ha->print();
	// cout<<ha->getPosition(2)->data<<endl;

	// cout<<ha->length()<<endl;
	// ha->insert(3,123);
	// cout<<ha->length()<<endl;
	return 0;
}
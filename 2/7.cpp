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

	Node(int data,Node* prev=NULL,Node* next=NULL){
		this->data=data;
		this->prev=prev;
		this->next=next;
	}

	Node(Node* prev=NULL,Node* next=NULL){
		this->prev=prev;
		this->next=next;
	}
};

class List{
private:
	Node* head;
	Node* tail;
	int  number;
public:
	List(){
		head=NULL;
		tail=NULL;
		number=0;
	}

	void append(int data){
		Node* node = new Node(data);
		if (!head)
		{
			head=node;
			tail=node;
			number++;
		}else{
			tail->next=node;
			node->prev=tail;
			tail=node;
			number++;
		}
	}

	int length(){
		return number;
	}

	void print(){
		Node* p=head;
		while(p->next){
			cout<<p->data<<endl;
			p=p->next;
		}
		cout<<p->data<<endl;
	}

	void convert(){
		int i=1;
		Node* p=head;
		Node* q=head;
		Node* temp=NULL;

		while(q->next!=NULL&&i<length()){
			if(i%2==0){
				q=q->next;

				p->prev->next=p->next;
				p->next->prev=p->prev;
				if (!tail->next)
				{
					p->next=NULL;
					p->prev=tail;
					tail->next=p;
					temp=p;
				}else{
					p->prev=tail;
					p->next=tail->next;
					tail->next=p;
					p->next->prev=p;
					//temp=p;
				}
				p=q;
			}else{
				q=q->next;
				p=q;
			}
			i++;
		}
		if(!temp)
			tail=temp;
	}

	//
};

int main(int argc, char const *argv[]){
	List* list=new List();
	for (int i = 0; i < 20; ++i)
	{
		list->append(i+1);
	}

	list->convert();
	list->print();

	//list->printTemp();
	return 0;
}
#include <iostream>
using namespace std;

class Node{
public:
	int data;
	Node* next;
public:
	Node(const int& a,Node* nextPtr=NULL){
		data=a;
		next=nextPtr;
	}
};

class List
{
public:
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
		}else{
			tail->next=node;
			tail=node;
			number++;
		}
	}
	int count(){
		return number;
	}
	~List(){
		Node* temp=NULL;
		while(head){
			temp=head->next;
			delete head;
			head=temp;
		}
	}
	void print(){
		if(head){
			Node* p=head;
			while(p->next){
				cout<<p->data<<endl;
				p=p->next;
			}
			cout<<p->data<<endl;
		}else{
			cout<<"no data"<<endl;
		}
	}

	void reverse(){
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
};

void merge(List* list1,List* list2,List* listMerged){
	Node* temp1=list1->head;
	Node* temp2=list2->head;

	while(temp1&&temp2){
		if ((temp1->data)<(temp2->data))
		{
			listMerged->append(temp1->data);

			if(temp1->next){
				temp1=temp1->next;
			}else{
				break;
			}
		}
		else{
			listMerged->append(temp2->data);

			if(temp2->next){
				temp2=temp2->next;
			}else{
				break;
			}
		}
	}

	while(temp1){
		listMerged->append(temp1->data);
		if(temp1->next){
			temp1=temp1->next;
		}else{
			break;
		}
	}
	while(temp2){
		listMerged->append(temp2->data);
		if (temp2->next)
		{
			temp2=temp2->next;
		}else{
			break;
		}
	}

	listMerged->reverse();
}

int main(int argc, char const *argv[])
{
	List *list1=new List();
	List *list2=new List();

	for (int i = 1; i <= 10; ++i)
	{
		list1->append(i);
	}
	for (int i = 0; i < 20; i+=2)
	{
		list2->append(i);
	}

	List *listMerged=new List();

	merge(list1,list2,listMerged);

	listMerged->print();
	
	return 0;
}
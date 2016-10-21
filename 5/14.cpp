#include <iostream>
using namespace std;

class Queue{
private:
	int maxSize;
	int front;
	int rear;
	int* queue;

public:
	Queue(int size){
		maxSize=size;
		queue=new int[maxSize];
		front=rear=0;
	}

	~Queue(){
		delete[] queue;
	}

	bool isEmpty(){
		if (front==rear)
		{
			return true;
		}
		return false;
	}

	bool isFull(){
		if ((rear+1)%maxSize==front)
		{
			return true;
		}
		return false;
	}

	void clear(){
		front=rear;
	}

	bool enQueue(const int item){
		if (isFull())
		{
			return false;
		}
		queue[rear]=item;
		rear=(rear+1)%maxSize;
		return true;
	}

	bool deQueue(int& item){
		if (isEmpty())
		{
			/* code */
			return false;
		}
		item=queue[front];
		front=(front+1)%maxSize;
		return true;
	}

	bool getFront(int& item){
		if (isEmpty())
		{
			return false;
		}
		item=queue[front];
		return true;
	}

	void printQueue(){
		int p = front;

		while(p!=rear){
			cout<<queue[p]<<endl;
			p++;
		}

		//cout<<queue[rear]<<endl;
	}
};

class Node{
public:
	Queue *data;
	Node* next;
	int sequence;

	Node(int seq,/*const Queue* q,*/int n,Node* nextPtr=NULL){
		sequence=seq;
		// data=q;
		data=new Queue(n);
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

	void append(int seq,int n){
		Node* node=new Node(seq,n);
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

	~List(){
		Node* temp=NULL;
		while(head->next){
			temp=head->next;
			delete head;
			head=temp;
		}
		delete head;
	}

	void printNode(){
		Node* p=head;

		while(p->next){
			p->data->printQueue();
			p=p->next;
		}

		p->data->printQueue();
	}

	void write(int num){
		Node* p=head;
		while(p->next){
			if (num==p->sequence)
			{
				p->data->enQueue(num);
				break;
			}else{
				p=p->next;
			}
		}
		if (num==tail->sequence)
		{
			tail->data->enQueue(num);
		}
	}
};

int main(int argc, char const *argv[])
{
	List* list=new List();
	int n=10;

	for (int i = 0; i < 10; ++i)
	{
		list->append(i,n);
	}

	list->write(1);

	list->write(3);

	list->write(4);

	list->write(4);
	list->write(4);
	list->write(2);
	list->write(2);
	list->write(6);
	list->write(7);
	list->write(8);
	list->write(0);
	list->write(9);
	list->write(6);
	list->write(5);

	list->printNode();
	return 0;
}
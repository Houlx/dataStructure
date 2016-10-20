#include <iostream>
using namespace std;

template<class T>
class Queue{
private:
	int maxSize;
	int front;
	int rear;
	int* queue;

public:
	Queue(int size){
		maxSize=size;
		queue=new T[maxSize];
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

	bool enQueue(const T item){
		if (isFull())
		{
			return false;
		}
		queue[rear]=item;
		rear=(rear+1)%maxSize;
		return true;
	}

	bool deQueue(T& item){
		if (isEmpty())
		{
			return false;
		}
		item=queue[front];
		front=(front+1)%maxSize;
		return true;
	}

	bool getFront(T& item){
		if (isEmpty())
		{
			return false;
		}
		item=queue[front];
		return true;
	}
};
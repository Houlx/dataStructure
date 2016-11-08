#include <iostream>
using namespace std;

template<class T>
class Queue{
private:
	int maxSize;
	int front;
	int rear;
	T* queue;

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

void pascalTriangle(int n){
	Queue<int> *q=new Queue<int>(1000);
	int s=0,t,u;
	q->enQueue(1);
	q->enQueue(1);
	for (int i = 1; i <= n; ++i)
	{
		q->enQueue(0);
		for (int j = 1; j <= i+2; ++j)
		{
			q->deQueue(t);
			u=s+t;
			q->enQueue(u);
			s=t;
			if (j!=i+2)
			{
				cout<<s<<"\t";
			}
		}
		cout << endl;
	}
}

int main(int argc, char const *argv[])
{
	Queue<int> *q=new Queue<int>(1000);
	pascalTriangle(10);
	return 0;
}
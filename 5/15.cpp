#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;

template<class T>
class RoundRobinQueue {
private:
	int maxSize;

	int front;
	int rear;
	T* queue;

	int tag;
	int flag;
public:
	RoundRobinQueue(int size){
		front=0;
		rear=0;
		tag=0;
		flag=0;
		maxSize=size;
		queue=new T[maxSize];
	}

	int empty(){
		if (tag==0)
		{
			return true;
		}
		return false;
	}

	bool isFull(){
		if (front==rear&&tag!=0)
		{
			return true;
		}
		return false;
	}

	bool enQueue(const T item){
		if (isFull())
		{
			return false;
		}
		queue[rear]=item;
		rear=(rear+1)%maxSize;
		flag++;
		tag=1;
		return true;
	}

	bool deQueue(T& item){
		if (!empty())
		{
			return false;
		}
		item=queue[front];
		front=(front+1)%maxSize;
		flag--;
		if (flag==0)
		{
			tag=0;
		}
		return true;
	}

	bool getFront(T& item){
		if (!empty())
		{
			return false;
		}
		item=queue[front];
		return true;
	}
};

int main(int argc, char const *argv[]){
	
	return 0;
}
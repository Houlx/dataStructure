#include <iostream>
using namespace std;

class ArrayStack{
private:
	int maxSize;
	int top;
	int* st;
public:
	ArrayStack(int size);
	ArrayStack();
	~ArrayStack();
	bool isFull();
	bool isEmpty();
	void clear();
	bool push(const int item);
	bool pop(int& item);
	bool Top(int& item);
};

ArrayStack::ArrayStack(int size){
	maxSize=size;
	top=-1;
	st=new int[maxSize];
}

ArrayStack::ArrayStack(){
	top=-1;
}

ArrayStack::~ArrayStack(){
	delete[] st;
}

bool ArrayStack::isFull(){
	if (top==maxSize-1)
	{
		cout<<"Stack is full."<<endl;
		return true;
	}
	return false;
}

bool ArrayStack::isEmpty(){
	if (top==-1)
	{
		cout<<"Stack is empty."<<endl;
		return true;
	}
	return false;
}
void ArrayStack::clear(){
	top=-1;
}

bool ArrayStack::push(const int item){
	if (isFull())
	{
		return false;
	}else{
		st[++top]=item;
		return true;
	}
}

bool ArrayStack::pop(int& item){
	if (isEmpty())
	{
		return false;
	}else{
		item=st[top--];
		return true;
	}
}

bool ArrayStack::Top(int& item){
	if (isEmpty())
	{
		cout<<"Stack is empty."<<endl;
		return false;
	}else{
		item=st[top];
		return true;
	}
}



int main(int argc, char const *argv[])
{
	ArrayStack *st=new ArrayStack(23);
	for (int i = 0; i < 10; ++i)
	{
		st->push(i+1);
	}

	int temp=0;
	while(st->pop(temp)){
		cout<<temp<<endl;
	}
	return 0;
}
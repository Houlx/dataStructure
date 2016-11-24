#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
//数制转换
class Stack {
private:
	int maxSize;
	int topItem;
	int* st;
public:
	Stack(int size);
	Stack();
	~Stack();
	bool isFull();
	bool isEmpty();
	void clear();
	bool push(const int item);
	bool pop(int& item);
	bool top(int& item);
};

Stack::Stack(int size){
	maxSize=size;
	topItem=-1;
	st=new int[maxSize];
}

Stack::Stack(){
	topItem=-1;
}

Stack::~Stack(){
	delete[] st;
}

bool Stack::isFull(){
	if (topItem==maxSize-1)
	{
		/* code */
		//cout<<"FULL"<<endl;
		return true;
	}
	return false;
}

bool Stack::isEmpty(){
	if (topItem==-1)
	{
		/* code */
		//cout<<"EMPTY"<<endl;
		return true;
	}
	return false;
}

void Stack::clear(){
	topItem=-1;
}

bool Stack::push(const int item){
	if (isFull())
	{
		/* code */
		return false;
	}else{
		st[++topItem]=item;
		return true;
	}
}

bool Stack::pop(int& item){
	if (isEmpty())
	{
		/* code */
		return false;
	}else{
		item=st[topItem--];
		return true;
	}
}

bool Stack::top(int& item){
	if (isEmpty())
	{
		/* code */
		cout<<"EMPTY"<<endl;
		return false;
	}else{
		item=st[topItem];
		return true;
	}
}

void convert(int n,int operand){
	Stack *temp=new Stack(100);
	while(operand){
		int a=operand%n;
		operand=operand/n;
		temp->push(a);
	}
	int b=0;

		if (n==16)
		{
			/* code */
			cout<<"0x";
			while(temp->pop(b)){
				switch(b){
				case 10:cout<<"A";break;
				case 11:cout<<"B";break;
				case 12:cout<<"C";break;
				case 13:cout<<"D";break;
				case 14:cout<<"E";break;
				case 15:cout<<"F";break;
				default:cout<<b;break;
				}
			}
		}

		if (n==8)
		{
			/* code */
			cout<<"0";
			while(temp->pop(b)){
				cout<<b;
			}
		}

		if (n==2)
		{
			/* code */
			while(temp->pop(b)){
				cout<<b;
			}
		}
	cout<<endl;
}
int main(int argc, char const *argv[]){
	convert(2,3636);
	convert(8,789);
	convert(16,15213);
	return 0;
}
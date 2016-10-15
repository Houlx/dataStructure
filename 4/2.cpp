#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
//回文游戏
class Stack {
private:
	int maxSize;
	int topItem;
	char* st;
public:
	Stack(int size);
	Stack();
	~Stack();
	bool isFull();
	bool isEmpty();
	void clear();
	bool push(const char item);
	bool pop(char& item);
	bool top(char& item);
};

Stack::Stack(int size){
	maxSize=size;
	topItem=-1;
	st=new char[maxSize];
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

bool Stack::push(const char item){
	if (isFull())
	{
		/* code */
		return false;
	}else{
		st[++topItem]=item;
		return true;
	}
}

bool Stack::pop(char& item){
	if (isEmpty())
	{
		/* code */
		return false;
	}else{
		item=st[topItem--];
		return true;
	}
}

bool Stack::top(char& item){
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

bool isPalindrome(char* str){
	Stack *temp=new Stack(100);
	char c=NULL;
	for (int i = 0; str[i]!='\0'; ++i)
	{
		/* code */
		temp->push(str[i]);
	}

	for (int i = 0; str[i]!='\0'; ++i)
	{
		/* code */
		temp->pop(c);
		if (str[i]!=c)
		{
			/* code */
			return false;
		}
	}
	return true;
}

int main(int argc, char const *argv[])
{
	char* str="123321";
	cout<<isPalindrome(str)<<endl;
	return 0;
}
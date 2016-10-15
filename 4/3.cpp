#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
using namespace std;
//括号匹配
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

bool brackets(char* str){
	Stack *temp=new Stack(100);
	char *p=str;
	char c=NULL;

	while(*p){
		switch(*p){
			case '{':
			case '[':
			case '(':
				temp->push(*p++);
				break;
			case '}':
			case ']':
			case ')':
				temp->pop(c);
				if ((c=='{' && *p=='}')||(c=='[' && *p==']')||(c=='(' && *p==')'))
				{
					p++;
				}
				else{
					return false;
				}
				break;
			default:p++;
		}
	}

	if (temp->isEmpty())
	{
		/* code */
		return true;
	}else{
		return false;
	}
}

int main(int argc, char const *argv[])
{
	char str[20]="(12(){}3[23]23{4})";
	char str2[20]="90034()}{}[[[]{";
	cout<<brackets(str)<<endl<<brackets(str2)<<endl;
	return 0;
}
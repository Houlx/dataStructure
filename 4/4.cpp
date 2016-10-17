#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <cmath>
using namespace std;
//表达式计算
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
	char pop();
	// bool top(char& item);
	char top();
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
char Stack::pop(){
	if (!isEmpty())
	{
		return st[topItem--];
	}
}
// bool Stack::top(char& item){
// 	if (isEmpty())
// 	{
// 		/* code */
// 		cout<<"EMPTY"<<endl;
// 		return false;
// 	}else{
// 		item=st[topItem];
// 		return true;
// 	}
// }
char Stack::top(){
	if (!isEmpty())
	{
		return st[topItem];
	}
}

int insidePriority(char c){
	switch(c){
		case '#':return 0;
		case '(':return 1;
		case '^':return 7;
		case '*':
		case '/':
		case '%':return 5;
		case '+':
		case '-':return 3;
		case ')':return 8;
		default:return -1;
	}
}

int outsidePriority(char c){
	switch(c){
		case '#':return 0;
		case '(':return 8;
		case '^':return 6;
		case '*':
		case '/':
		case '%':return 4;
		case '+':
		case '-':return 2;
		case ')':return 1;
		default: return -1;
	}
}

double oneStep(char operand1,char operand2,char optr){
	switch(optr){
		case '+':return (double)(operand1-48)+(operand2-48);
		case '-':return (double)(operand1-48)-(operand2-48);
		case '*':return (double)(operand1-48)*(operand2-48);
		case '/':return (double)(operand1-48)/(operand2-48);
		case '^':return pow((double)(operand1-48),(double)(operand2-48));
	}
}
double calculate(char* str){
	Stack *OPTR=new Stack(100);
	Stack *OPRD=new Stack(100);
	char* p=str;
	char operand1 = NULL;
	char operand2 = NULL;
	char temp = NULL;

	OPTR->push('#');

	while((*p)!=NULL){
		if ((*p)>=48&&(*p)<=57)
		{
			OPRD->push(*p++);
		}
		else if (outsidePriority(*p)!=-1){
			{
				if (outsidePriority(*p)>insidePriority(OPTR->top()))
				{
					OPTR->push(*p++);
				}
				else if (outsidePriority(*p)<insidePriority(OPTR->top()))
				{
					if (OPRD->pop(operand1)&OPRD->pop(operand2))
					{
						OPRD->push((char)oneStep(operand2,operand1,OPTR->pop())+48);
					}
				}
				if (outsidePriority(*p)==insidePriority(OPTR->top()))
				{
					temp=OPTR->pop();
					p++;
				}
			}
		}
	}

	return OPRD->top();
}

int main(int argc, char const *argv[])
{
	cout<<calculate("3*(7-2)#")<<endl;
	return 0;
}
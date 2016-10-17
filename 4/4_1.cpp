#include <iostream>
#include <cmath>
using namespace std;

template<class T>
class Stack{
private:
	int maxSize;
	int topItem;
	T* st;
public:
	Stack(int size);
	Stack();
	~Stack();
	bool isFull();
	bool isEmpty();
	void clear();
	bool push(const T item);
	bool pop(T& item);
	T pop();
	T top();
};
template<class T>
Stack<T>::Stack(int size){
	maxSize=size;
	topItem=-1;
	st=new T[maxSize];
}
template<class T>
Stack<T>::Stack(){
	top=-1;
}
template<class T>
Stack<T>::~Stack(){
	delete[] st;
}
template<class T>
bool Stack<T>::isFull(){
	if (topItem==maxSize-1)
	{
		return true;
	}
	return false;
}
template<class T>
bool Stack<T>::isEmpty(){
	if (topItem==-1)
	{
		return true;
	}
	return false;
}
template<class T>
void Stack<T>::clear(){
	top=-1;
}
template<class T>
bool Stack<T>::push(const T item){
	if (isFull())
	{
		return false;
	}else{
		st[++topItem]=item;
		return true;
	}
}
template<class T>
bool Stack<T>::pop(T& item){
	if (isEmpty())
	{
		return false;
	}else
	{
		item=st[topItem--];
		return true;
	}
}
template<class T>
T Stack<T>::pop(){
	if (!isEmpty())
	{
		return st[topItem--];
	}
}
template<class T>
T Stack<T>::top(){
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

double oneStep(double operand1,double operand2,char optr){
	switch(optr){
		case '+':return operand1+operand2;
		case '-': return operand1-operand2;
		case '*':return operand1*operand2;
		case '/': return operand1/operand2;
		case '^': return pow(operand1,operand2);
	}
}

double calculate(char* str){
	Stack<double> *OPRD=new Stack<double>(100);
	Stack<char> *OPTR=new Stack<char>(100);
	char* p=str;
	double operand1=0,operand2=0;
	double operand=0;
	char temp=NULL;

	OPTR->push('#');

	while(*p){
		while ((*p)>='0'&&(*p)<='9')
		{
			operand=operand*10+double(*p)-48;
			p++;
		}
		if (operand != 0) {
			OPRD->push(operand);
			operand = 0;
		}
		if (outsidePriority(*p)!=-1){
			{
				if (outsidePriority(*p)>insidePriority(OPTR->top()))
				{
					OPTR->push(*p++);
				}
				else if (outsidePriority(*p)<insidePriority(OPTR->top()))
				{
					if (OPRD->pop(operand1)&&OPRD->pop(operand2))
					{
						OPRD->push(oneStep(operand2,operand1,OPTR->pop()));
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
	cout<<calculate("32*(72/23)#")<<endl;
	return 0;
}


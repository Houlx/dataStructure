#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H
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

#endif
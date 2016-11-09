/*
   本测试题目目标是巩固单链表的相关操作
   请大家完成有todo注释的成员函数的定义,相应功能已经注释
   根据main中的提示的测试步骤来完成各个成员函数的测试

    循序渐进,提升编程信心,完善设计思维
*/

#include <iostream>
#include<stack>
using namespace std;
/* 栈定义开始  */

template <class T>
class Stack{
public:
	Stack(int MaStackSize=10);
	~Stack() { delete [] stack;}
	bool IsEmpty() const {return top==-1;}
	bool IsFull() const {return top==MaxTop;}
	T Top() const;
	bool push(const T& x);
	bool pop(T& x);
	void MakeEmpty(){top=-1;} //清空栈
private:
	int top;//栈顶
	int MaxTop;//最大的栈顶值
	T *stack;//堆栈元素数组
};
template<class T>
Stack<T>::Stack(int MaxStackSize)
{
	MaxTop=MaxStackSize-1;
	stack=new T[MaxStackSize];
	top=-1;
}

template<class T>
T Stack<T>::Top() const
{
	if(IsEmpty())
	{cout<<"no element";return -1;}
	else
		return stack[top];
}
template<class T>
bool Stack<T>::push(const T& x)
{
	if(IsFull())
	{cout<<"no memory;"<<endl;return false;}
	top=top+1;
	stack[top]=x;
	return true;
}
template<class T>
bool Stack<T>::pop(T& x)
{
	if(IsEmpty())
	{cout<<"no element"<<endl;return false;}
	x=stack[top];
	top=top-1;
	return true;
}
/*  栈定义结束   */
//////////////////////////////////////////////////////////////
/*  链表定义开始  */
class Node  //定义结点类型
{
public:
	int data;  //存放数据
	Node* next; //存放后继结点地址
	Node(int val,Node* ptr = 0)  //构造函数,初始化数据成员
	{
		data = val;
		next = ptr;
	}
};
class List
{
public:
	Node* head; //记录表头结点地址

	List()
	{
		head = new Node(0,0);//构造带有表头结点的空的单向链表
	}
	void insertToHead(int x)
	{
		//向表头插入数据值为x的结点
		Node* newNode = new Node(x,0);
		newNode->next = head->next;
		head->next = newNode;
	}

	~List()
	{
		//todo: 1-释放链表的所有结点
		Node* p=head;
		Node* q;
		while(p){
			q=p;
			p=p->next;
			delete q;
		}
	}
	void print()
	{
		// todo: 2-依次输出链表的各个结点的数据值
		Node *p=head;
        while(p->next)
        {
            cout<<p->next->data<<" ";
            p=p->next;
        }
        cout<<endl;
	}
	void moveMinToFirst()
	{
		//todo:3-将链表中数据域值最小的那个链结点移到链表的最前面。
		//要求：不得额外申请新的链结点
		Node *p=head;
        Node *p2=head;
		int num=p->next->data;

		Node *pmin=p->next ;

		while(p->next)
        {
            if(num>p->next->data)
            {
                num=p->next->data;
                pmin=p->next;
            }
            p=p->next;
        }

        while(p2->next!=pmin)
        {
            p2=p2->next;
        }
        p2->next=p2->next->next;
        p=head->next;
        head->next=pmin;
        pmin->next=p;
	}
	void delItem(int val)
	{
		//todo:4-删除第一个数据值为val的结点
		Node *p1=head;
		while(p1->next->data!=val)
        {
            p1=p1->next;
        }
        Node *pde=p1->next;
        p1->next=pde->next;
        delete pde;
	}
	void reverse()
	{
		//todo:5-利用栈将单链表的结点反转
		 stack<Node*>a;
        Node *p1=head;
        while(p1->next)
        {
            a.push(p1->next);
            p1=p1->next;
        }
        p1=a.top();
        Node *p2=p1;
        a.pop();
        while(!a.empty())
        {
            p1->next=a.top();
            a.pop();
            p1=p1->next;

         //   cout<<1<<endl;
        }
        p1->next=NULL;
      //  cout<<2;
        head->next=p2;
	}
};
/*  链表定义结束  */
////////////////////////////////////////

/* main测试开始  */
int main()
{
	List mylist;

	//必须补充: 循环调用insertToHead方法向mylist中添加数据
	int num;
    cin>>num;
    while(num>0)
    {
        mylist.insertToHead(num);
        cin>>num;
    }

	/* 下面开始测试各个成员函数,
	可以在实现每个测试目标的时候注释掉为完成其他测试目标而添加的代码*/

	//测试目标1: 测试析构函数----不需添加任何代码

	//测试目标2:测试print方法
	  //   mylist.print();

	//测试目标3:测试 moveMinToFirst方法,执行 moveMinToFirst后利用print输出结果来查看
	//mylist.moveMinToFirst();
	   //  mylist.print();

	//测试目标4:测试delItem方法,执行 delItem后利用print输出结果来查看
	//mylist.delItem(3);
    //mylist.print();

	//测试目标5:测试reverse方法,执行reverse后利用print输出结果来查看
	 mylist.reverse();
    mylist.print();

}
/* main测试结束  */

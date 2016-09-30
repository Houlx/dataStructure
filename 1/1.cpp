#include <iostream>
using namespace std;
bool FindValue(int* A,int n,int x){
	for (int i = 0; i < n; ++i)
	{
		if (A[i]==x)
		{
			return true;
		}
	}
	return false;
}

void BubbleSort(int* A,int n){
	for (int i = 0; i < n-1; ++i)
	{
		for (int j = 0; j < n-i-1; ++j)
		{
			if (A[j]>A[j+1])
			{
				int temp;
				temp=A[j];
				A[j]=A[j+1];
				A[j+1]=temp;
			}
		}
	}
}

int Count(int* A,int n){
	int result=0;
	int flag=0;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (A[i]==A[j])
			{
				flag++;
			}
		}
		if (flag==1)
		{
			result++;
			flag=0;
		}
		else{
			flag=0;
		}
	}
	return result;
}

void Merge(int* A,int m1,int* B,int m2,int* C){
	int* temp1=A;
	int* temp2=B;
	while(A<(temp1+m1)&&B<(temp2+m2)){
		if (*A<*B)
		{
			*C=*A;
			A++;
		}else{
			*C=*B;
			B++;
		}
		C++;
	}

	while(A<(temp1+m1)){
		*(C++)=*(A++);
	}

	while(B<(temp2+m2)){
		*(C++)=*(B++);
	}
}
double compute(double a,double b,char opt){
	double result=0;
	switch(opt){
		case '+':
		result=a+b;break;
		case '-':
		result=a-b;break;
		case '*':
		result=a*b;break;
		case '/':
		result=a/b;break;
	}
	return result;
}

int main(int argc, char const *argv[])
{
	int ARR[10]={234,5,2,78,456,798,1234,5,5,2};
//查找
	if (FindValue(ARR,10,78))
	{
		cout<<"找到."<<endl;
	}

	cout<<endl<<endl;
//冒泡排序
	BubbleSort(ARR,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<ARR[i]<<endl;
	}

	cout<<endl<<endl;

//统计不重复
	cout<<"不重复:"<<Count(ARR,10);

	cout<<endl<<endl;

//合并数组
	int ARR2[10]={1,4,7,90,200,500,1000,1100,1200,1300};
	int ARR3[20]={0};
	Merge(ARR,10,ARR2,10,ARR3);
	for (int i = 0; i < 20; ++i)
	{
		cout<<ARR3[i]<<endl;
	}

	cout<<endl<<endl;
//算术运算
	double a=231.231,b=34.12;
	cout<<compute(a,b,'+')<<endl;
	cout<<compute(a,b,'-')<<endl;
	cout<<compute(a,b,'*')<<endl;
	cout<<compute(a,b,'/')<<endl;

	cout<<endl;
	cout<<endl;
	return 0;
}
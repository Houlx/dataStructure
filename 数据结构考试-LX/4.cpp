//设整数序列（a0, a1,a2,…,an-1）存储于一维数组A中，编写求解最小值的 递归 程序。
#include <iostream>
using namespace std;
int min(int a[], int start, int end)
{
	if (start == end)
		return a[start];
	int v = min(a,start + 1, end);
	return a[start]<v?a[start]:v;
}
int main(int argc, char const *argv[])
{
	int arr[10]={2,4,5,2,-1,6,4,7,4,5};
	cout<<min(arr,0,9);
	return 0;
}
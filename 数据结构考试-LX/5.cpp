//已知整型元素的线性表（a0, a1,a2,…,an-1）按顺序存储于一维数组A中，编写函数将各个元素向右移动k位 ：void movek（int A[], int n, int k）;即数据变为  an-k, …,an-1,a0,…,an-k-1
#include <iostream>
using namespace std;
void movek(int a[], int n, int k) {
	int *temp=new int[k];
	for (int i = n - k, j = 0; i < n; ++i, ++j)
	{
		temp[j] = a[i];
	}
	for (int i = n - 1 - k, j = n - 1; i >= 0; --i, --j)
	{
		a[j] = a[i];
	}
	for (int i = 0, j = 0; i < k; ++i, ++j)
	{
		a[i] = temp[j];
	}
}
int main(int argc, char const *argv[])
{
	int arr[10] = {0};
	for (int i = 0; i < 10; ++i)
	{
		arr[i] = i;
	}
	movek(arr, 10, 7);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

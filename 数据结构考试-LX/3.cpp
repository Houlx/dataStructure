//已知线性表（a0, a1,a2,…,an-1）按顺序存于内存，每个元素都是整数，试设计把所有值小于a0的元素移到值大于等于a0的元素前边void Move（int a[], int n）。（要求时间最少，辅助空间最少）
#include <iostream>
using namespace std;
void move(int a[], int n) {

	int i, j;
	int tmp;

	for ( i = 0, j = n - 1; i < j; i++ )
	{
		while (a[i] < a[0])
		{
			i++;
		}

		while (a[j] > a[0])
		{
			j--;
		}

		if (i < j)
		{
			tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		}
	}
}
int main(int argc, char const * argv[])
{
	int arr[10] = {5,1,2,3,4,6,7,8,9,0};
	move(arr, 10);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
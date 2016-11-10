#include <iostream>
using namespace std;
void movek(int a[], int n, int k) {
	int *temp=new int[k];
	for (int i = 0; i < k; ++i)
	{
		temp[i] = a[i];
	}
	for (int i = 0, j = k; j < n; ++i, ++j)
	{
		a[i] = a[j];
	}
	for (int i = n-k, j = 0; i < n; ++i, ++j)
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
	movek(arr, 10, 3);
	for (int i = 0; i < 10; ++i)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

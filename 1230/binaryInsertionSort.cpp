#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random(int n) {
	return (rand() % n) + 1;
}

void binaryInsertionSort(int data[], int n) {
	int left, mid, right, p;
	for (p = 1; p < n; p++) {
		int temp = data[p];
		left = 0;
		right = p - 1;
		while (left <= right) {
			mid = (left + right) / 2;
			if (data[mid] > temp) {
				right = mid - 1;
			}
			else {
				left = mid + 1;
			}
		}
		for (int i = p - 1; i >= left; i--) {
			data[i + 1] = data[i];
		}
		data[left] = temp;
	}
}

int main(int argc, char const *argv[])
{
	srand((int)time(0));
	int data[10];
	for (int i = 0; i < 10; i++) {
		data[i] = random(100);
		cout << data[i] << " ";
	}
	cout << endl;
	binaryInsertionSort(data, 10);
	for (int i = 0; i < 10; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
	return 0;
}
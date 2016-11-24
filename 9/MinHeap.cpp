#include <iostream>
using namespace std;

template <class T>
class MinHeap {
private:
	T* heapArray;
	int currentSize;
	int maxSize;

public:
	MinHeap(T* array, int num, int max) {
		heapArray = new T[max];
		for (int i = 0; i < num; i++) {
			heapArray[i] = array[i];
		}
		currentSize = num;
		maxSize = max;
	}

	void initHeap();

	void print() {
		for (int i = 0; i < currentSize; i++) {
			cout << heapArray[i] << " ";
		}
	}

	bool isLeaf(int) const;
	int LChild(int) const;
	int RChild(int) const;
	bool remove(int, T&);
	void siftUp(int);
	void siftDown(int);
	void moveMax();

	bool insert(const T&);

	T& removeMax();
};

template <class T>
void MinHeap<T>::initHeap() {
	for (int i = currentSize / 2 - 1; i >= 0; i--) {
		siftDown(i);
	}
}

template <class T>
void MinHeap<T>::siftDown(int left) {
	int i = left;
	int j = 2 * i + 1;
	T temp = heapArray[i];

	while (j < currentSize) {
		if ((j < currentSize - 1) && (heapArray[j] > heapArray[j + 1])) {
			j++;
		}
		if (temp > heapArray[j])
		{
			heapArray[i] = heapArray[j];
			i = j;
			j = 2 * j + 1;
		}
		else {
			break;
		}
	}
	heapArray[i] = temp;
}

template <class T>
bool MinHeap<T>::insert(const T&) {
	if (currentSize <= maxSize) {
		heapArray[currentSize] = T;
		currentSize++;

	}
}

int main(int argc, char const *argv[])
{
	int arr[] = { 20, 12, 35, 15, 10, 80, 30 };
	MinHeap<int> heap(arr, 7, 20);
	heap.initHeap();
	heap.print();
	return 0;
}
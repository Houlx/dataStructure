#include <iostream>
using namespace std;

template <class T>
class MaxHeap {
private:
	T* heapArray;
	int currentSize;
	int maxSize;

public:
	MaxHeap(T* array, int num, int max) {
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

	bool isLeaf(int position) const {
		if (!heapArray[2 * position + 1] && !heapArray[2 * position + 2]) {
			return true;
		} else {
			return false;
		}
	}
	int LChild(int position) const {
		if (heapArray[2 * position + 1]) {
			return 2 * position + 1;
		} else {
			return -1;
		}
	}
	int RChild(int position) const {
		if (heapArray[2 * position + 2]) {
			return 2 * position + 2;
		} else {
			return -1;
		}
	}
	bool remove(int position, T& item) {
		item = heapArray[position];
		heapArray[position] = heapArray[currentSize - 1];
		currentSize--;
		if (currentSize > 1) {
			siftDown(0);
		}
	}
	void siftUp(int);
	void siftDown(int);
	// void moveMin();

	bool insert(const T&);

	T& removeMax();
};

template <class T>
void MaxHeap<T>::initHeap() {
	for (int i = currentSize / 2 - 1; i >= 0; i--) {
		siftDown(i);
	}
}

template <class T>
void MaxHeap<T>::siftUp(int position) {
	int child = position;
	int parent = (child - 1) / 2;

	T temp = heapArray[position];

	while (parent >= 0 && child >= 1) {
		if (heapArray[parent] < temp) {
			heapArray[child] = heapArray[parent];
			child = parent;
			parent = (child - 1) / 2;
		} else {
			break;
		}
	}
	heapArray[child] = temp;
}

template <class T>
bool MaxHeap<T>::insert(const T& item) {
	if (currentSize < maxSize) {
		heapArray[currentSize] = item;
		currentSize++;
	}
	siftUp(currentSize - 1);
}
template <class T>
void MaxHeap<T>::siftDown(int left) {
	int i = left;
	int j = 2 * i + 1;
	T temp = heapArray[i];

	while (j < currentSize) {
		if ((j < currentSize - 1) && (heapArray[j] < heapArray[j + 1])) {
			j++;
		}
		if (temp < heapArray[j])
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
T& MaxHeap<T>::removeMax() {
	T temp = 0;
	if (currentSize == 0) {
		cout << "cannot delete" << endl;
		return temp;
	}
	else {
		temp = heapArray[0];
		heapArray[0] = heapArray[currentSize - 1];
		currentSize--;
		if (currentSize > 1) {
			siftDown(0);
		}
		return temp;
	}
}

int main(int argc, char const *argv[])
{
	int arr[] = { 20, 12, 35, 15, 10, 80, 30 };
	MaxHeap<int> heap(arr, 7, 20);
	heap.initHeap();
	heap.print();
	cout << endl;
	heap.removeMax();
	heap.print();
	cout << endl;
	heap.insert(3);
	heap.print();
	cout<<endl;
	int temp;
	heap.remove(2,temp);
	heap.print();
	return 0;
}
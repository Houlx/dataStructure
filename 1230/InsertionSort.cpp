#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

int random(int n){
	return (rand()%n)+1;
}

void insertionSort(int data[],int n){
	int i,p;
	for(p=1;p<n;p++){
		int temp=data[p];
		i=p-1;
		while(i>=0 && data[i]>temp){
			data[i+1]=data[i];
			i--;
		}
		data[i+1]=temp;
	}
}

int main(int argc, char const *argv[])
{
	srand((int)time(0));

	int data[10];
	for(int i=0;i<10;i++){
		data[i]=random(100);
		cout<<data[i]<<" ";
	}
	cout<<endl;
	insertionSort(data,10);
	for(int i=0;i<10;i++){
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return 0;
}
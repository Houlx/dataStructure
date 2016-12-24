#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int random(int n){
	return (rand()%n)+1;
}
void bubbleSort(int data[],int n){
	for(int i=0;i<n;i++){
		for(int j=1;j<n-i;j++){
			if(data[j]<data[j-1]){
				int temp=data[j];
				data[j]=data[j-1];
				data[j-1]=temp;
			}
		}
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
	bubbleSort(data,10);
	for (int i = 0; i < 10; ++i)
	{
		cout<<data[i]<<" ";
	}
	cout<<endl;
	return 0;
}
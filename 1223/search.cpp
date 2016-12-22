#include <iostream>
using namespace std;

int sequenceSearch(int data[],int n,int key){
	for (int i = 0; i < n; ++i)
	{
		if(data[i]==key){
			return i;
		}
	}
	return -1;
}

int biSearch(int data[],int n,int key){
	int left=0;
	int right=n-1;
	int mid;
	while(left<=right){
		mid=(left+right)/2;
		if(key<data[mid]){
			right=mid-1;
		}else if(key>data[mid]){
			left=mid+1;
		}else{
			return mid;
		}
	}
	return -1;
}

int main(){
	int data[20];
	for(int i=0;i<20;i++){
		data[i]=i*3-2;
	}
	cout<<sequenceSearch(data,20,10);
	cout<<endl;
	cout<<biSearch(data,20,25);
}
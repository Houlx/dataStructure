#include <iostream>
using namespace std;

class ArrayList{
private:
	int* arrayList;
	int maxSize;
	int curLen;
	int position;

public:
	ArrayList(const int size){
		maxSize=size;
		arrayList=new int[maxSize];
		curLen=0;
		position=0;
	}
	~ArrayList(){
		delete [] arrayList;
	}

	void print(){
		for (int i = 0; i < curLen; ++i)
		{
			cout<<arrayList[i]<<endl;
		}
	}
	void clear(){
		delete [] arrayList;
		curLen=0;
		position=0;
		arrayList=new int[maxSize];
	}

	int length(){
		return curLen;
	}

	bool append(const int n){
		if (curLen>=maxSize)
		{
			cout<<"array is full."<<endl;
			return false;
		}
		else{
			arrayList[curLen]=n;
			curLen++;
			return true;
		}
	}

	int findMin(){
		int min=arrayList[0];
		for (int i = 0; i < curLen; ++i)
		{
			if (arrayList[i]<min)
			{
				min=arrayList[i];
			}
		}
		return min;
	}
	//(1)删除具有最小值的元素并返回其值，空出的位置由最后一个元素填补
	int deleteMin();
	//(2)删除具有给定值x的所有元素
	void deleteValueX(int x);
	//(3)从有序顺序表中删除其值在给定值s与t之间的所有元素
	void deleteValueFromStoT(int s,int t);
};

int ArrayList::deleteMin(){
	int min=findMin();
	for (int i = 0; i < curLen; ++i)
	{
		if (arrayList[i]==min)
		{
			arrayList[i]=arrayList[curLen-1];
			arrayList[curLen-1]=0;
			curLen--;
			i=-1;
		}
	}
	return min;
}

void ArrayList::deleteValueX(int x){
	for (int i = 0; i < curLen; ++i)
	{
		if (arrayList[i]==x)
		{
			for(int j=i;j<curLen-1;j++){
				arrayList[j]=arrayList[j+1];
			}
			arrayList[curLen-1]=0;
			curLen--;
		}
	}
}

void ArrayList::deleteValueFromStoT(int s,int t){
	if (s>=t)
	{
		cout<<"error"<<endl;
	}else{
		for (int i = 0; i < curLen; ++i)
		{
			if ((arrayList[i]>=s)&&(arrayList[i]<=t))
			{
				for (int j = i; j < curLen-1; ++j)
				{
					arrayList[j]=arrayList[j+1];
				}
				arrayList[curLen-1]=0;
				curLen--;
				i=-1;
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	ArrayList *arr=new ArrayList(10);
	for (int i = 0; i < 6; ++i)
	{
		arr->append(i);
	}

	arr->append(0);

	cout<<arr->length();
	cout<<endl<<endl;

	cout<<arr->deleteMin();
	cout<<endl<<endl;

	arr->deleteValueX(4);

	arr->deleteValueFromStoT(1,2);

	arr->print();

	arr->clear();
	return 0;
}
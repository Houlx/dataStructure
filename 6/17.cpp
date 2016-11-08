#include <iostream>
using namespace std;

int strcmp(char* str1,char* str2){
	while(*str1==*str2){
		if (*str1=='\0')
		{
			/* code */
			return 0;
		}
		str1++;
		str2++;
	}
	return *str1-*str2;
}

int main(int argc, char const *argv[])
{
	cout<<strcmp("abcd","");
	return 0;
}
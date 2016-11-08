#include <string>
#include <cstring>
#include <cassert>
#include <iostream>
using namespace std;

int nativeMatching(const string& T,const string& P){
	int p=0;
	int t=0;
	int plen=P.length();
	int tlen=T.length();
	if (tlen<plen)
	{
		/* code */
		return -1;
	}

	while(p<plen&&t<tlen){
		if (T[t]==P[p])
		{
			/* code */
			p++;
			t++;
		}
		else{
			t=t-p+1;
			p=0;
		}
	}
	if (p>=plen)
	{
		/* code */
		return (t-plen);
	}else{
		return -1;
	}
}

int main(int argc, char const *argv[])
{
	cout<<nativeMatching("dsasdcadwoecaoer","as");
	return 0;
}
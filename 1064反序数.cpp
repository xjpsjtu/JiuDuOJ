#include<iostream>
#include<string.h>
using namespace std;

bool judge(int a)
{
	int t1=a%10;
	int t2=(a/10)%10;
	int t3=(a/100)%10;
	int t4=(a/1000)%10;
	int b=t1*1000+t2*100+t3*10+t4;
	if(a*9==b)return true;
	else return false;
}

int main()
{
	int a;
	for(a=1000;a<=1111;a++){
		if(judge(a))cout<<a<<endl;
	}
	return 0;
}



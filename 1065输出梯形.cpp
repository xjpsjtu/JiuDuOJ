#include<iostream>
using namespace std;

int main()
{
	int h;
	while(cin>>h){
	int low=h+2*(h-1);
	int i,k;
	for(i=0;i<h;i++)
	{
		int a=h+i*2;
		for(k=0;k<low-a;k++)cout<<" ";
		for(k=low-1;k>low-a-1;k--)cout<<"*";
		cout<<endl;
	}
	}
	return 0;
}


#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int a,b;
	while(cin>>a>>b&&(a||b)){
		int k;
		cin>>k;
		int ak,bk;
		ak=a%(int)pow(10,k);
		bk=b%(int)pow(10,k);
		if(ak==bk)cout<<-1<<endl;
		else cout<<a+b<<endl;
	}
	return 0;
}
#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n&&n){
		int a=n*n;
		int flag=1;
		while(n){
			if(n%10!=a%10){
				flag=0;break;
			}
			n/=10;
			a/=10;
		}
		if(flag==1)cout<<"Yes!"<<endl;
		else cout<<"No!"<<endl;
	}
	return 0;
}


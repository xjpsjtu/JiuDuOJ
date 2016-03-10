#include<iostream>
#include<math.h>
using namespace std;

int main()
{
	int n;
	while(cin>>n){
		if(n==0||n==1||n<0){cout<<"no"<<endl;}
		else{
			int q=sqrt(n);
			int i=2;
			bool flag=true;
			for(i=2;i<n;i++){
				if(n%i==0){flag=false;break;}
			}
			if(flag)cout<<"yes"<<endl;
			else cout<<"no"<<endl;
		}
	}
	return 0;
}
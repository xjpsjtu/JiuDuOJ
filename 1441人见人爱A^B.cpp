#include<iostream>
using namespace std;

int A,B;
int num[30];

int p(int k)
{
	if(k==0)return A%1000;
	else return p(k-1)*p(k-1)%1000;
}

int main()
{
	while(cin>>A>>B){
		if(A==0&&B==0)break;
		int size=0;
		while(B!=0){
			num[size++]=B%2;
			B/=2;
		}
		int ans=1;
		int i;
		for(i=0;i<size;i++){
			if(num[i]==0)continue;
			else ans=ans*p(i)%1000;
		}
		ans=ans%1000;
		cout<<ans<<endl;
	}
	return 0;
}




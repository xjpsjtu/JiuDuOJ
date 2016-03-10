#include<iostream>
using namespace std;

#define m 200907
long long num[5];

int fun1(int n)
{
	return (num[0]%m+(n%m-1)*(num[1]%m-num[0]%m))%m;
}

int fun2(int n)
{
	long long q=num[1]/num[0];
	int k=n-1;//ÒªËãq^k%m
	long long ans=num[0];
	while(k!=0){
		if(k%2==1){
			ans=(ans*q)%m;
		}
		k/=2;
		q=q*q%m;
	}
	return ans%m;
}

int main()
{
	int N;
	cin>>N;
	while(N--){
		int i;
		for(i=0;i<3;i++){
			cin>>num[i];
		}
		int n;
		cin>>n;
		if(num[0]+num[2]==2*num[1])cout<<fun1(n);
		else cout<<fun2(n);
		cout<<endl;
	}
	return 0;
}
		








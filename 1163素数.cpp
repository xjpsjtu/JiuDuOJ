#include<iostream>
using namespace std;

int prime[10000];
int primesize;
bool flag[10002];

void Init()
{
	primesize=0;
	int i,j;
	for(i=1;i<=10000;i++)flag[i]=true;
	for(i=2;i<=10000;i++){
		if(flag[i]==false)continue;
		for(j=i*i;j<=10000;j+=i){
			flag[j]=false;
		}
		prime[primesize++]=i;
	}
	
}

int main()
{
	Init();
	int n;
	while(cin>>n){
		int sum=0;
		int i;
		for(i=0;i<primesize;i++){
			if(prime[i]<n&&prime[i]%10==1)sum++;
		}
		if(sum>0){
			for(i=0;i<primesize;i++){
			if(prime[i]<n&&prime[i]%10==1){
				cout<<prime[i];
				sum--;
				if(sum>0)cout<<" ";
				}
			}
		}
		else cout<<-1;
		cout<<endl;
	}
	return 0;
}
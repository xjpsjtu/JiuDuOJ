#include<iostream>
#include<math.h>
using namespace std;

#define max 1010
int prime[max];
bool flag[max];
int primesize;
int nn[max];//n的质因数组
int aa[max];//a的质因数组


void Init()
{
	int i,j;
	primesize=0;
	for(i=1;i<=max;i++)flag[i]=true;
	for(i=2;i<=max;i++){
		if(flag[i]==false)continue;
		else{
			for(j=i*i;j<=max;j+=i)flag[j]=false;
			prime[primesize++]=i;
		}
	}
}

bool isPrime(int n)
{
	int i;
	int bound=(int)sqrt(n)+1;
	for(i=2;i<bound;i++){
		if(n%i==0)return false;
	}
	return true;
}

int main()
{
	Init();
	int n,a;
	while(cin>>n>>a){
		int i;
		for(i=0;i<max;i++){
			nn[i]=0;
			aa[i]=0;
		}
		for(i=0;i<primesize;i++){
			int t=n;
			while(t){
				nn[i]+=t/prime[i];
				t=t/prime[i];
			}
		}
		int ans=123123123;
		for(i=0;i<primesize;i++){
			while(a%prime[i]==0){
				aa[i]++;
				a/=prime[i];
			}
			if(aa[i]==0)continue;
			if(nn[i]/aa[i]<ans)ans=nn[i]/aa[i];
		}
		cout<<ans<<endl;
	}
	return 0;
}

		
			
		






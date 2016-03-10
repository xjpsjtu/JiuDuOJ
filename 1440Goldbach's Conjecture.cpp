#include<iostream>
#include<math.h>
using namespace std;

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
	int n;
	while(cin>>n&&n){
		int a;
		int ans=0;
		for(a=2;a<=n/2;a++){
			if(isPrime(a)&&isPrime(n-a))ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
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

int nextP(int a)
{
	int i;
	for(i=a+1;;i++){
		if(isPrime(i))break;
	}
	return i;
}

int main()
{
	int k;
	while(cin>>k){
		int p=2;
		int kk=k-1;
		while(kk--){
			p=nextP(p);
		}
		cout<<p<<endl;
	}
	return 0;
}


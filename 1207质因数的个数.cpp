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
	while(cin>>n){
		int i;
		int sum=0;
		int bound=(int)sqrt(n)+1;
		for(i=2;i<=bound;i++){
			while(n%i==0){
				sum++;
				n=n/i;
			}
		}
		if(n>1)sum++;
		cout<<sum<<endl;
	}
	return 0;
}

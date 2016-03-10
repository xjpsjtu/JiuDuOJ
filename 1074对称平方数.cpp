#include<iostream>
#include<math.h>
#include<string.h>

using namespace std;

bool judge(int n)
{
	int k=(int)(log10(n));//n=121,k=2
	if(k%2==1)return false;
	else{
		int flag=1;
		int kk=k/2;
		int i;
		for(i=1;i<=kk;i++){
			int x=(n/((int)(pow(10,i-1))))%10;
			int y=(n/((int)(pow(10,2*kk+1-i))))%10;
			if(x!=y){flag=0;break;}
		}
		if(flag)return true;
		else return false;
	}
}

int main(){
	int k;
	for(k=0;k<256;k++){
		if(judge(k*k))cout<<k<<endl;
	}
	return 0;
}




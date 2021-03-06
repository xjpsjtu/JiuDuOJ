#include<iostream>
#include<math.h>
#include<iomanip>
using namespace std;

int main()
{
	long n,m;
	while(cin>>m>>n&&m){
		int left=m,right=m;
		int deep_diff=0;
		int count=0;
		int deep_n=(int)(log(n)/log(2)+1);
		int deep_m=(int)(log(m)/log(2)+1);
		deep_diff=deep_n-deep_m;
		count+=(int)pow(2,deep_diff)-1;
		for(int i=1;i<=deep_diff;++i)
		{
			left=2*left;
			right=2*right+1;
		}
		if(right<=n)count+=right-left+1;
		else if(left<=n)count+=n-left+1;
		cout<<count<<endl;
	}
	return 0;
}

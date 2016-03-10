#include<iostream>
using namespace std;

int main()
{
	int N,M;
	int i,j;
	while(cin>>N&&N)
	{
		int tree[10000]={0};
		for(i=0;i<=N;i++)tree[i]=1;
		cin>>M;
		int a[100][2];
		for(i=0;i<M;i++)cin>>a[i][0]>>a[i][1];
		for(i=0;i<M;i++){
			for(j=a[i][0];j<=a[i][1];j++)tree[j]*=0;
		}
		int sum=0;
		for(i=0;i<=N;i++)sum+=tree[i];
		cout<<sum<<endl;
	}
	return 0;
}

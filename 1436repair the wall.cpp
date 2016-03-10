#include<iostream>
#include<algorithm>
using namespace std;

int compare(int a,int b)
{
	return a>b;
}

int main()
{
	int L,N;
	while(cin>>L>>N&&L){
		int a[600];
		int i;
		for(i=0;i<N;i++){
			cin>>a[i];
		}
		int sum=0;
		int count=0;
		sort(a,a+N,compare);
		for(i=0;i<N;i++){
			sum+=a[i];
			if(sum>=L){count++;break;}
			else count++;
		}
		if(i<N)cout<<count<<endl;
		else cout<<"impossible"<<endl;
	}
	return 0;
}



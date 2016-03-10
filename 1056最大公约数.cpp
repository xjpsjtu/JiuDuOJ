#include<iostream>
using namespace std;

int euclid(int m,int n)
{
	if(n==0)return m;
	else if(m==0)return n;
	else{
		int max=m>=n?m:n;
		int min=m>=n?n:m;
		int tmp;
		while(min!=0){
			tmp=max;
			max=min;
			min=tmp%min;
		}
		return max;
	}
}

int main()
{
	int x,y;
	while(cin>>x>>y){
		cout<<euclid(x,y)<<endl;
	}
	return 0;
}

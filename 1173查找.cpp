#include<iostream>
#include<algorithm>
using namespace std;

int main()
{
	int a[100],b[100];
	int n;
	int i,j;
	while(cin>>n&&n)
	{
		for(i=0;i<n;i++)cin>>a[i];
		sort(a,a+n);
		int m;
		cin>>m;
		for(j=0;j<m;j++)
		{
			cin>>b[j];
		}
		for(j=0;j<m;j++){
			int s=b[j];
			int low=0;
			int top=n-1;
			int mid;
			while(low<=top){
				mid=(low+top)/2;
				if(s<a[mid]){top=mid-1;}
				else if(s>a[mid]){low=mid+1;}
				else if(s==a[mid])break;
			}
			if(low>top)cout<<"NO"<<endl;
			else cout<<"YES"<<endl;
		}
	}
	return 0;
}







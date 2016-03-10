#include<iostream>
using namespace std;

int main()
{
	int n;
	cin>>n;
	while(n--){
		int i,k;
		cin>>k;
		int a[80];
		bool aa[80]={false};
		for(i=0;i<k;i++)cin>>a[i];
		if(a[0]!=a[1])aa[0]=true;
		for(i=1;i<k-1;i++){
			if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))aa[i]=true;
		}
		if(a[k-1]!=a[k-2])aa[k-1]=true;
		int sum=0;
		for(i=0;i<k;i++){
			if(aa[i])sum++;
		}
		for(i=0;i<k;i++){
			if(aa[i]){cout<<i;sum--;if(sum)cout<<" ";}
		}
		cout<<endl;
	}
	return 0;
}

		


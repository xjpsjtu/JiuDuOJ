#include<iostream>
#include<math.h>
using namespace std;

int main(){
	int n;
	while(cin>>n&&n){
		int a[1000];
		int i;
		for(i=1;i<=n;i++)cin>>a[i];
		int d;
		cin>>d;
		int first=pow(2,d-1);
		int end=pow(2,d)-1<=n?pow(2,d)-1:n;
		int count=end-first+1;
		for(i=first;i<=end;i++){
			cout<<a[i];
			count--;
			if(count>0)cout<<" ";
		}
		cout<<endl;
	}
	return 0;
}

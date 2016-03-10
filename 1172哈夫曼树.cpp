#include<iostream>
#include<queue>
using namespace std;

priority_queue<int,vector<int>,greater<int> >Q;

int main()
{
	int n;
	while(cin>>n&&n){
		while(Q.empty()==false)Q.pop();
		int i;
		for(i=1;i<=n;i++){
			int x;
			cin>>x;
			Q.push(x);
		}
		int ans=0;
		while(Q.size()>1){
			int a=Q.top();
			Q.pop();
			int b=Q.top();
			Q.pop();
			ans+=a+b;
			Q.push(a+b);
		}
		cout<<ans<<endl;
	}
	return 0;
}


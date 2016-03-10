#include<iostream>
using namespace std;
#define N 1000
int tree[N];
int findRoot(int x){
	if(tree[x]==-1)return x;
	else{
		int tmp=findRoot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

int main()
{
	int n,m;
	while(cin>>n&&n){
		cin>>m;
		int i;
		for(i=1;i<=n;i++){
			tree[i]=-1;
		}
		while(m--){
			int a,b;
			cin>>a>>b;
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)tree[a]=b;
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(tree[i]==-1)ans++;
		}
		if(ans==1)cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
#include<iostream>
using namespace std;

#define N 1000
int Tree[N];
int findRoot(int x){
	if(Tree[x]==-1)return x;
	else{
		int tmp=findRoot(Tree[x]);
		Tree[x]=tmp;
		return tmp;
	}
}
int main()
{
	int n,m;
	while(cin>>n&&n!=0){
		cin>>m;
		int i;
		for(i=1;i<=n;i++){
			Tree[i]=-1;
		}
		while(m--){
			int a,b;
			cin>>a>>b;
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b)Tree[a]=b;
		}
		int ans=0;
		for(i=1;i<=n;i++){
			if(Tree[i]==-1)ans++;
		}
		cout<<ans-1<<endl;
	}
	return 0;
}
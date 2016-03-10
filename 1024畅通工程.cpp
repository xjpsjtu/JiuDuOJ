#include<iostream>
#include<algorithm>
using namespace std;
#define N 105
int tree[N];
int findRoot(int x){
	if(tree[x]==-1)return x;
	else{
		int tmp=findRoot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

struct road{
	int a,b;
	int cost;
}r[N];

int compare(road x,road y){
	return x.cost<y.cost;
}

int main()
{
	int n,m;
	while(cin>>n>>m&&n){
		int i;
		for(i=1;i<=m;i++){
			tree[i]=-1;
		}
		for(i=0;i<n;i++){
			cin>>r[i].a>>r[i].b>>r[i].cost;
			int aa=findRoot(r[i].a);
			int bb=findRoot(r[i].b);
			if(aa!=bb){
				tree[aa]=bb;
			}
		}
		int ans=0;
		for(i=1;i<=m;i++){
			if(tree[i]==-1)ans++;
		}
		if(ans>1){cout<<"?"<<endl;continue;}
		else{
			int total_cost=0;
			for(i=1;i<=m;i++){
				tree[i]=-1;
			}
			sort(r,r+n,compare);
			for(i=0;i<n;i++){
				int aa=findRoot(r[i].a);
				int bb=findRoot(r[i].b);
				if(aa!=bb){
					tree[aa]=bb;
					total_cost+=r[i].cost;
				}
			}
			cout<<total_cost<<endl;
		}
	}
	return 0;
}
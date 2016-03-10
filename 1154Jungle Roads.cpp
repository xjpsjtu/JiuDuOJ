#include<iostream>
#include<algorithm>
using namespace std;

#define N 27
int tree[N];
int findRoot(int x){
	if(tree[x]==-1)return x;
	else{
		int tmp=findRoot(tree[x]);
		tree[x]=tmp;
		return tmp;
	}
}

struct edge{
	int a,b;
	int cost;
}e[500];

int compare(edge x,edge y){
	return x.cost<y.cost;
}

int main()
{
	int n;
	while(cin>>n&&n){
		int i,j;
		int size=0;
		for(i=0;i<n;i++){
			tree[i]=-1;
		}
		for(i=0;i<n-1;i++){
			char firstletter;
			cin>>firstletter;
			int num;
			cin>>num;
			for(j=0;j<num;j++){
				char nextletter;
				cin>>nextletter;
				int length;
				cin>>length;
				e[size].a=firstletter-'A';
				e[size].b=nextletter-'A';
				e[size].cost=length;
				size++;
			}
		}
		sort(e,e+size,compare);
		int total_length=0;
		for(i=0;i<size;i++){
			int x=findRoot(e[i].a);
			int y=findRoot(e[i].b);
			if(x!=y){
				tree[x]=y;
				total_length+=e[i].cost;
			}
			else continue;
		}
		cout<<total_length<<endl;
	}
	return 0;
}
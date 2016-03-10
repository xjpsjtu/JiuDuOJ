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

struct data
{
	int start;
	int end;
	int length;
}d[5008];

int compare(data a,data b){
	return a.length<=b.length;
}

int main(){
	int n;
	while(cin>>n&&n){
		int i;
		int m=n*(n-1)/2;
		for(i=0;i<m;i++){
			cin>>d[i].start>>d[i].end>>d[i].length;
		}
		sort(d,d+m,compare);
		for(i=0;i<=n;i++){
			tree[i]=-1;
		}
		int total_length=0;
		for(i=0;i<m;i++){
			int a=d[i].start;
			int b=d[i].end;
			a=findRoot(a);
			b=findRoot(b);
			if(a!=b){tree[a]=b;total_length+=d[i].length;}
			else continue;
		}
		cout<<total_length<<endl;
	}
	return 0;
}

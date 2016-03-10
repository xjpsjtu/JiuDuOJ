#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

struct room{
	double F;
	double j;
};

int compare(room a,room b){
	return (a.j/a.F)>(b.j/b.F);
}

int main()
{
	int m,n;
	while(cin>>m>>n&&m>0)
	{
		int i;
		room r[1000];
		for(i=0;i<n;i++){
			cin>>r[i].j>>r[i].F;
		}
		sort(r,r+n,compare);
		double sumj=0;
		double sumF=m;
		double sum=0;
		int k=0;
		for(k=0;k<n;k++){
			sum+=r[k].F;
			if(sum<=sumF){sumj+=r[k].j;}
			else break;
		}
		if(k<n){sumj+=(sumF-(sum-r[k].F))*r[k].j/r[k].F;cout<<setiosflags(ios::fixed)<<setprecision(3)<<sumj<<endl;}
		else cout<<setiosflags(ios::fixed)<<setprecision(3)<<sumj<<endl;
	}
	return 0;
}


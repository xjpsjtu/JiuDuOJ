//要注意double的精度问题，包括判断相等和大小

#include<iostream>
#include<algorithm>
#include<iomanip>
using namespace std;

double fabs(double a){
	return a>0?a:-1;
}

int main()
{
	int C;
	cin>>C;
	while(C--)
	{
		int n,v,w;
		cin>>n>>v>>w;
		int i;
		double p[100];
		for(i=0;i<n;i++){
			cin>>p[i];
		}
		int sum=0;
		double vm=0.00;
		double s;//浓度
		sort(p,p+n);
		if(w<p[0]){sum=0;s=0;cout<<sum<<" "<<setiosflags(ios::fixed)<<setw(2)<<setprecision(2)<<s<<endl;continue;}
		for(i=0;i<n;i++){
			sum+=v;
			vm+=v*p[i]/100.0;
			s=vm/sum*100;
			if(s-w>1e-8)break;
		}
		if(i>=n){cout<<sum<<" ";cout<<setiosflags(ios::fixed)<<setw(2)<<setprecision(2)<<s/100<<endl;}
		else{
			sum-=v;
			vm-=v*p[i]/100.0;
			s=vm/sum;
			cout<<sum<<" ";cout<<setiosflags(ios::fixed)<<setw(2)<<setprecision(2)<<s<<endl;
		}
	}
	return 0;
}


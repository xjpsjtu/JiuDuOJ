#include<iostream>
using namespace std;

#define Max_Num 1000010

int a[Max_Num];

int main()
{
	int n,m;
	int i;
	while(cin>>n&&n!=0){
		cin>>m;
		for(i=0;i<Max_Num;i++)a[i]=0;
		for(i=0;i<n;i++){int x;cin>>x;a[x+500000]++;}
		for(i=Max_Num-1;i>-1;i--){
			if(a[i]==1){
				cout<<i-500000;m--;
				if(m!=0)cout<<" ";
				else{
					cout<<endl;
					break;
				}
			}
			
		}
	}
	return 0;
}
		
					

	
#include<iostream>
using namespace std;

int main()
{
	
	int N,M;
	int i,j;
	while(cin>>N&&N!=0){
		cin>>M;
		int sum[200]={0}; 
		int book[200]={0};
		for(i=0;i<N;i++){cin>>book[i];}
		for(i=0;i<N;i++){
			for(j=0;j<N;j++){
				if(book[i]==book[j])sum[i]++;
			}
		}
		for(i=0;i<N;i++){
			if(sum[i]>=2)cout<<sum[i]-1<<endl;
			else cout<<"BeiJu"<<endl;
		}
	}
	return 0;
}




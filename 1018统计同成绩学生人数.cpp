#include<iostream>
using namespace std;

int main()
{
	
	int N;
	int i;
	int c[1000];
	while(cin>>N&&N!=0){
		int s[101]={0};
		for(i=0;i<N;i++){cin>>c[i];s[c[i]]++;}
		int x;
		cin>>x;
		cout<<s[x]<<endl;
	}
	
	return 0;
}
		

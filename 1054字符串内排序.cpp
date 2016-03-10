#include<iostream>
#include<algorithm>
using namespace std;

bool comp(char a,char b)
{
	return (a-b)<0;
}

int main(){
	char str[201];
	while(cin>>str&&strcmp(str,"0")!=0)
	{
		int len=strlen(str);
		sort(str,str+len,comp);
		cout<<str<<endl;
	}
	return 0;
}
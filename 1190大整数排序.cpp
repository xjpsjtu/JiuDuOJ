#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;

struct longInt
{
	char str[1005];
};

bool compare(longInt a,longInt b)
{
	int len1=strlen(a.str);
	int len2=strlen(b.str);
	if(len1<len2)return true;
	else if(len1>len2)return false;
	else{
		int i;
		for(i=0;i<len1;i++){
			if(a.str[i]==b.str[i])continue;
			else if(a.str[i]<b.str[i])return true;
			else return false;
		}
	}
}

int main()
{
	longInt s[100];
	int n;
	while(cin>>n){
		int i;
		for(i=0;i<n;i++){
			cin>>s[i].str;
		}
		sort(s,s+n,compare);
		for(i=0;i<n;i++){
			cout<<s[i].str<<endl;
		}
	}
	return 0;
}
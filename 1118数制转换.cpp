#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

void print(long n,int p)
{
	if(n<p){
		char ch;
		if(n>9)ch=n-10+'A';
		else ch=n+'0';
		cout<<ch;
		return;
	}
	else {
		print(n/p,p);
		char ch;
		if(n%p>9)ch=n%p-10+'A';
		else ch=n%p+'0';
		cout<<ch;
	}
}


void trans(int a,char str[],int b)
{
	int len=strlen(str);
	int i;
	int sum=0;
	for(i=len-1;i>-1;i--){
		int x;
		if(str[i]>='0'&&str[i]<='9')x=str[i]-'0';
		else if(str[i]>='A'&&str[i]<='Z')x=str[i]-'A'+10;
		else x=str[i]-'a'+10;
		sum+=x*(int)(pow(a,-i+len-1));
	}
	
	print(sum,b);
}

int main()
{
	int a,b;
	char str[100];
	while(cin>>a&&a){
		cin>>str>>b;
		trans(a,str,b);
		cout<<endl;
	}
	return 0;
}
	

		



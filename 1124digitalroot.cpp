#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;

char str2[1000];

char *trans(char *str)
{
	int sum=0;
	int i;
	int len=strlen(str);
	for(i=0;i<len;i++){
		sum+=(str[i]-'0');
	}
	int size=0;
	while(sum>0){
		str2[size++]=sum%10+'0';
		sum=sum/10;
	}
	str2[size]='\0';
	return &str2[0];
}

int main()
{
	char str[1000];
	while(cin>>str&&strcmp(str,"0")!=0){
		int len=strlen(str);
		char *st=str;
		while(len>1){
			
			st=trans(st);
			
			len=strlen(st);
		}
		cout<<st<<endl;
	}
	return 0;
}
			
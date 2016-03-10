#include<iostream>
#include<string.h>
using namespace std;



char mu(char str[])
{
	int len=strlen(str);
	if((str[len-1]-'0')%2==0)return '0';
	else return '1';
}

char* divi(char *str)
{
	int len;
	len=strlen(str);
	int i;
	int index=0;
	for(i=0;i<len;i++){
		int k=str[i]-'0'+index*10;
		index=k%2;
		k=k/2;
		str[i]=k+'0';
	}
	str[len]=0;
	return str;
}

bool zero(char *str){
	bool flag=true;
	for(int i=0;i<strlen(str);i++){
		if(str[i]){
			flag=false;
			break;
		}
	}
	return flag;
}

int main()
{
	char str[40];
	while(cin>>str){
		char *s=str;
		char ans[50];
		int size=0;
		do{
			ans[size++]=mu(s);
			s=divi(s);
		}while(!zero(s));
	}
	return 0;
}
			






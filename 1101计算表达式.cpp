#include<iostream>
#include<stack>
#include<string.h>
using namespace std;


bool isNum(char a)
{
	return (a>='0'&&a<='9');
}
int main()
{
	char str[205];
	while(cin>>str)
	{
		int len=strlen(str);
		stack<double> in;
		while(!in.empty())in.pop();
		int i=0;
		while(i<len)
		{
			if(isNum(str[i])&&!isNum(str[i+1])){in.push((double)(str[i]-'0'));i++;}
			else if(isNum(str[i])&&isNum(str[i+1])){
				double sum=0;
				int index=i;
				while(isNum(str[index])){
					sum=sum*10;
					sum+=(double)(str[index]-'0');
					index++;
				}
				i=index;
				in.push(sum);
			}
			else if(str[i]=='*'){
				int index=i+1;
				double sum=0;
				while(isNum(str[index])){
					sum*=10;
					sum+=(double)(str[index]-'0');
					index++;
				}
				i=index;
				double tmp=sum*in.top();
				in.pop();
				in.push(tmp);
			}
			else if(str[i]=='/'){
				int index=i+1;
				double sum=0;
				while(isNum(str[index])){
					sum*=10;
					sum+=str[index]-'0';
					index++;
				}
				i=index;
				double tmp=in.top()/sum;
				in.pop();
				in.push(tmp);
			}
			else {i++;}
		}
		stack<int> inn;
		while(!in.empty()){
			double tmp=in.top();
			inn.push(tmp);
			in.pop();
		}
		
		for(i=0;i<len;i++){
			if(str[i]=='+'){
				double a=inn.top();
				inn.pop();
				double b=inn.top();
				inn.pop();
				inn.push(a+b);
			}
			else if(str[i]=='-'){
				double a=inn.top();
				inn.pop();
				double b=inn.top();
				inn.pop();
				inn.push(a-b);
			}
			else continue;
		}
		cout<<inn.top()<<endl;
	}
	return 0;
}






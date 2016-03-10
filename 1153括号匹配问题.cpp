#include<iostream>
#include<stack>
using namespace std;

stack<int> s;
char str[110];
char ans[110];
int main()
{
	while(cin>>str)
	{
		int i;
		for(i=0;str[i]!='\0';i++)
		{
			if(str[i]=='('){s.push(i);ans[i]=' ';}
			else if(str[i]==')'){
				if(s.empty()==false){
					s.pop();
					ans[i]=' ';
				}
				else ans[i]='?';
			}
			else ans[i]=' ';
		}
		while(s.empty()==false){
			ans[s.top()]='$';
			s.pop();
		}
		ans[i]='\0';
		cout<<str<<endl;
		cout<<ans<<endl;
	}
	int x;
	cin>>x;
	return 0;
}

		

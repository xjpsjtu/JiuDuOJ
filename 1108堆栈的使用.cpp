#include<iostream>
#include<stack>
#include<string>
using namespace std;

stack<int> s;
int main(){
	int n;
	while(cin>>n&&n){
		while(!s.empty()){
			s.pop();
		}
		int temp;
		char a;
		while(n--){
			cin>>a;
			switch(a){
				case 'P':cin>>temp;s.push(temp);break;
				case 'O':if(!s.empty())s.pop();break;
				case 'A':if(s.empty())cout<<"E"<<endl;
						 else cout<<s.top()<<endl;
						 break;
			}
		}
		cout<<endl;
	}
	return 0;
}

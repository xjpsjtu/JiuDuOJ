#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct bigInteger{
	int digit[1000];
	int size;
	void init(){
		for(int i=0;i<1000;i++)digit[i]=0;
		size=0;
	}
	void set(char str[]){
		init();
		int len=strlen(str);
		for(int i=len-1,j=0,t=0,c=1;i>=0;i--){
			t+=(str[i]-'0')*c;
			j++;
			c*=10;
			if(j==4||i==0){
				digit[size++]=t;
				j=0;
				t=0;
				c=1;
			}
		}
	}
};

int main()
{
	char a[1000],b[1000];
	while(cin>>a>>b){
		if(strcmp(a,"0")==0&&strcmp(b,"0")==0){cout<<0<<endl;continue;}
		bigInteger aa,bb,ans;
		ans.init();
		aa.set(a);
		bb.set(b);
		int index=0;
		int i;
		for(i=0;i<1000;i++){
			int tmp;
			tmp=aa.digit[i]+bb.digit[i]+index;
			index=tmp/10000;
			tmp%=10000;
			ans.digit[i]=tmp;
		}
		bool flag=false;
		bool flag2=true;
		
		for(i=1000;i>=0;i--){
			if(ans.digit[i]==0&&!flag)continue;
			else if(flag2){
				flag=true;flag2=false;
				cout<<ans.digit[i];
			}
			else cout<<setw(4)<<setfill('0')<<ans.digit[i];
		}
		cout<<endl;
	}
	return 0;
}

			


		

	
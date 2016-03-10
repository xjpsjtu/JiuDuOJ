#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct bigInteger{
	int digit[10000];
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

	void print(){
		int i;
		for(i=size-1;i>=0;i--){
			if(i!=size-1)cout<<setw(4)<<setfill('0')<<digit[i];
			else cout<<digit[i];
		}
	}

	bigInteger operator +(const bigInteger &a)const{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<a.size||i<size;i++){
			int tmp=a.digit[i]+digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ans.digit[ans.size++]=tmp;
		}
		if(carry!=0){
			ans.digit[ans.size++]=carry;
		}
		return ans;
	}

	bigInteger operator *(int &a)const{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<size;i++){
			int tmp=a*digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ans.digit[ans.size++]=tmp;
		}
		if(carry!=0)ans.digit[ans.size++]=carry;
		return ans;
	}
};

int main()
{
	int n;
	while(cin>>n){
		bigInteger a;
		a.init();
		a.set("1");
		int i;
		for(i=1;i<=n;i++){
			a=a*i;
		}
		a.print();
		cout<<endl;
	}
	return 0;
}



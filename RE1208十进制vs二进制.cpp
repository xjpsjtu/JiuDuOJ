#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct bigInteger
{
	int a[1000];
	int size;

	void init(){
		int i;
		for(i=0;i<1000;i++){
			a[i]=0;
		}
		size=0;
	}

	void set(char str[])
	{
		init();
		int len=strlen(str);
		for(int i=len-1,j=0,t=0,c=1;i>-1;i--){
			t+=(str[i]-'0')*c;
			c*=10;
			j++;
			if(j==4||i==0){
				a[size++]=t;
				j=0;
				t=0;
				c=1;
			}
		}
	}

	void set(int x)
	{
		init();
		do{
			a[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	}

	void print()
	{
		int i;
		for(i=size-1;i>-1;i--){
			if(i!=size-1)cout<<setw(4)<<setfill('0')<<a[i];
			else cout<<a[i];
		}
	}

	bigInteger operator +(const bigInteger &B)const
	{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<size||i<B.size;i++){
			int tmp=a[i]+B.a[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ans.a[ans.size++]=tmp;
		}
		if(carry!=0)ans.a[ans.size++]=carry;
		return ans;
	}

	bigInteger operator *(int x)const
	{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<size;i++){
			int tmp=x*a[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ans.a[ans.size++]=tmp;
		}
		if(carry!=0)ans.a[ans.size++]=carry;
		return ans;
	}


	bigInteger operator /(int x)const{
		bigInteger ans;
		ans.init();
		int i;
		int remainder=0;
		for(i=size-1;i>-1;i--){
			int t=(a[i]+remainder*10000)/x;
			int r=(a[i]+remainder*10000)%x;
			ans.a[ans.size++]=t;
			remainder=r;
		}
		ans.size=0;
		for(i=0;i<1000;i++){
			if(ans.a[i]!=0)ans.size=i;
		}
		ans.size++;
		return ans;
	}

	int operator %(int x)const{
		int i;
		int remainder=0;
		for(i=size-1;i>-1;i--){
			int t=(a[i]+remainder*10000)/x;
			int r=(a[i]+remainder*10000)%x;
			remainder=r;
		}
		return remainder;

	}
}B,C,D;

int main(){
	char str[1000];
	while(cin>>str){
		B.set(str);
		int ans[10000];
		int size=0;
		do{
			int t=B%2;
			B=B/2;
			ans[size++]=t;
		}while(B.a[0]!=0||B.size!=1);
		int i;
		C.init();
		for(i=0;i<size;i++){
			D.init();
			D.set(ans[i]);
			C=C*2+D;
		}
		C.print();
		cout<<endl;
	}
	return 0;
}
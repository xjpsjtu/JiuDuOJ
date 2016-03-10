#include<iostream>
#include<string.h>
#include<iomanip>
using namespace std;

struct bigInteger{
	int digit[1000];
	int size;
	//初始化
	void init(){
		int i;
		for(i=0;i<1000;i++)digit[i]=0;
		size=0;
	}
	//普通整数赋值
	void set(int x){
		init();
		do{
			digit[size++]=x%10000;
			x/=10000;
		}while(x!=0);
	}
	void print(){
		for(int i=size-1;i>=0;i--){
			if(i!=size-1)cout<<setw(4)<<setfill('0')<<digit[i]<<"$";
			else cout<<digit[i]<<"$";
		}
	}
	bigInteger operator *(int x)const{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<size;i++){
			int tmp=x*digit[i]+carry;
			carry=tmp/10000;
			tmp=tmp%10000;
			ans.digit[ans.size++]=tmp;
		}
		if(carry!=0)ans.digit[ans.size++]=carry;
		return ans;
	}
	bigInteger operator +(const bigInteger &a)const{
		bigInteger ans;
		ans.init();
		int carry=0;
		int i;
		for(i=0;i<size||i<a.size;i++){
			int tmp=digit[i]+a.digit[i]+carry;
			carry=tmp/10000;
			tmp%=10000;
			ans.digit[ans.size++]=tmp;
		}
		if(carry!=0)ans.digit[ans.size++]=carry;
		return ans;
	}
	bigInteger operator /(int x)const{
		bigInteger ans;
		ans.init();
		int remainder=0;
		int i;
		for(i=size-1;i>-1;i--){
			int t=(remainder*10000+digit[i])/x;
			int r=(remainder*10000+digit[i])%x;
			ans.digit[i]=t;
			remainder=r;
		}
		ans.size=0;
		for(i=0;i<1000;i++){
			if(ans.digit[i]!=0)ans.size=i;
		}
		ans.size++;
		return ans;
	}
	int operator %(int x)const {
		int remainder=0;
		int i;
		for(i=size-1;i>=0;i--){
			int t=(remainder*10000+digit[i])/x;
			int r=(remainder*10000+digit[i])%x;
			remainder=r;
		}
		return remainder;
	}
}a,b,c;

char str[10000];
char ans[10000];

int main()
{
	int n,m;
	while(cin>>n>>m){
		cin>>str;
		int len=strlen(str);
		a.set(0);
		b.set(1);
		int i;
		for(i=len-1;i>=0;i--){
			int t;
			if(str[i]>='0'&&str[i]<='9'){
				t=str[i]-'0';
			}
			else t=str[i]-'A'+10;
			a=a+b*t;
			b=b*n;
		}
		int size=0;
		do{
			int t=a%m;
			if(t>=10)ans[size++]=t-10+'a';
			else ans[size++]=t+'0';
			a=a/m;
		}while(a.digit[0]!=0||a.size!=1);
		for(i=size-1;i>=0;i--)cout<<ans[i];
		cout<<endl;
	}
	return 0;
}

		




	
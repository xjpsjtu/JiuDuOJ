#include<iostream>
#include<string.h>
using namespace std;

struct doub{
	int a[100];	//整数部分
	int b[100];	//小数部分
	int asize;
	int bsize;	//小数位数

	void init(){
		int i;
		for(i=0;i<100;i++)a[i]=0;
		for(i=0;i<100;i++)b[i]=0;
		asize=0;
		bsize=0;
	}

	void set(char str[]){
		init();
		int len=strlen(str);
		int i;
		for(i=0;i<len;i++){
			if(str[i]=='.')break;
		}
		int point=i;
		for(i=point-1;i>-1;i--){
			a[asize++]=str[i]-'0';
		}
		for(i=len-1;i>point;i--){
			b[bsize++]=str[i]-'0';
		}
	}

	doub operator +(doub &d)const{
		doub ans;
		ans.init();
		if(bsize>d.bsize){
			int index=bsize-d.bsize;
			int temp[100];
			int i;
			for(i=0;i<index;i++){
				temp[i]=0;
			}
			for(i=index;i<d.bsize+index;i++){
				temp[i]=d.b[i-index];
			}
			int carry=0;
			//先处理小数部分
			for(i=0;i<bsize;i++){
				int tmp=b[i]+temp[i]+carry;
				carry=tmp/10;
				tmp%=10;
				ans.b[ans.bsize++]=tmp;
			}
			for(i=0;i<asize||i<d.asize;i++){
				int tmp=a[i]+d.a[i]+carry;
				carry=tmp/10;
				tmp%=10;
				ans.a[ans.asize++]=tmp;
			}
			if(carry!=0)ans.a[ans.asize++]=carry;
		}
		else if(bsize<=d.bsize){
			int index=d.bsize-bsize;
			int temp[100];
			int i;
			for(i=0;i<index;i++){
				temp[i]=0;
			}
			for(i=index;i<bsize+index;i++){
				temp[i]=b[i-index];
			}
			int carry=0;
			for(i=0;i<d.bsize;i++){
				int tmp=temp[i]+d.b[i]+carry;
				carry=tmp/10;
				tmp%=10;
				ans.b[ans.bsize++]=tmp;
			}
			for(i=0;i<asize||i<d.asize;i++){
				int tmp=a[i]+d.a[i]+carry;
				carry=tmp/10;
				tmp%=10;
				ans.a[ans.asize++]=tmp;
			}
			if(carry!=0)ans.a[ans.asize++]=carry;
		}
		return ans;
	}
	void print(){
		int i;
		if(asize<=1){
			for(i=0;i<asize;i++)cout<<a[i];
		}
		else{
			bool flag=false;
			for(i=asize-1;i>-1;i--){
				if(a[i]==0&&flag==false)continue;
				else{
					flag=true;
					cout<<a[i];
				}
			}
			if(flag==false)cout<<0;
		}
		cout<<".";
		int s=0;
		for(i=0;i<bsize;i++){
			if(b[i]==0)s++;
		}
		if(bsize<=1){
			for(i=0;i<bsize;i++)cout<<b[i];
		}
		else{
			bool flag2=false;
			for(i=bsize-1;i>s-1;i--){
				if(b[i]==0&&flag2==false)continue;
				else{
					flag2=true;
					cout<<b[i];
				}
			}
			if(flag2==false)cout<<0;
		}
	}
}db1,db2,ans;

int main(int argc, char const *argv[])
{
	int n;
	cin>>n;
	while(n--){
		char str1[105],str2[105];
		cin>>str1>>str2;
		db1.init();
		db2.init();
		db1.set(str1);
		db2.set(str2);
		ans.init();
		ans=db1+db2;
		ans.print();
		cout<<endl;
	}
	return 0;
}



































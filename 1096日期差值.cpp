#include<iostream>
using namespace std;

int mon[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};

int isR(int x)
{
	return x%100!=0&&x%4==0||x%400==0?1:0;
}

class Date{
public:
	int day;
	int month;
	int year;
	void nextDay(){
		day++;
		if(day>mon[month][isR(year)]){
			day=1;
			month++;
			if(month>12){
				month=1;
				year++;
			}
		}
	}
};

int abss(int x){
	return x<0?-x:x;
}

int buf[5001][13][32];
int main(){
	Date temp;
	int count=0;
	temp.day=1;
	temp.month=1;
	temp.year=0;
	while(temp.year!=5001){
		buf[temp.year][temp.month][temp.day]=count;
		temp.nextDay();
		count++;
	}
	char str1[8],str2[8];
	int d1,m1,y1;
	int d2,m2,y2;
	while(1){
		cin>>str1>>str2;
		cout<<str1<<'\t'<<str2<<endl;
		d1=(str1[6]-'0')*10+str1[7]-'0';
		m1=(str1[4]-'0')*10+str1[5]-'0';
		y1=(str1[0]-'0')*1000+(str1[1]-'0')*100+(str1[2]-'0')*10+str1[3]-'0';
		d2=(str2[6]-'0')*10+str2[7]-'0';
		m2=(str2[4]-'0')*10+str2[5]-'0';
		y2=(str2[0]-'0')*1000+(str2[1]-'0')*100+(str2[2]-'0')*10+str2[3]-'0';
		cout<<y1<<m1<<d1<<endl;
		cout<<y2<<m2<<d2<<endl;
		//cout<<abss((buf[y2][m2][d2]-buf[y1][m1][d1]))+1<<endl;
	}
	return 0;
}
	










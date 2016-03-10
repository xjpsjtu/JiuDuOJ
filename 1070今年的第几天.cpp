#include<iostream>
using namespace std;

int isR(int year)
{
	if((year%4==0&&year%100!=0)||year%400==0)return 1;
	else return 0;
}

int mon[32][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};

class Date
{
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

int abss(int a)
{
	return a>0?a:-a;
}

int buf[5001][13][32];

int main()
{
	Date temp;
	temp.day=1;
	temp.month=1;
	temp.year=0;
	int count=0;
	while(temp.year!=5001){
		buf[temp.year][temp.month][temp.day]=count;
		temp.nextDay();
		count++;
	}
	int d1,m1,y1;
	while(cin>>y1>>m1>>d1){
		cout<<buf[y1][m1][d1]-buf[y1][1][1]+1<<endl;
	}
	return 0;
}
	

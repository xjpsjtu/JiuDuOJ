#include<iostream>
#include<string.h>
using namespace std;

int IsR(int a)
{
	if(a%4==0&&a%100!=0||a%400==0)return 1;
	else return 0;
}

int mon[13][2]={0,0,31,31,28,29,31,31,30,30,31,31,30,30,31,31,31,31,30,30,31,31,30,30,31,31};

class Date
{
public:int day,month,year;
	   void nextDay(){
		   day++;
		   if(day>mon[month][IsR(year)]){
			   day=1;
			   month++;
			   if(month>12){
				   month=1;
				   year++;
			   }
		   }
	   }
};

char monthName[13][20]={" ","January","February","March","April","May","June","July","August","September","October","November","December"};
char weekName[7][20]={"Sunday","Monday","Tuesday","Wednesday","Thursday","Friday","Saturday"};

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
	int d,m,y;
	char s[20];
	while(cin>>d>>s>>y){
		for(m=1;m<=12;m++){
			if(strcmp(s,monthName[m])==0)break;
		}
		int days=buf[y][m][d]-buf[2001][10][9];
		days=days+2;
		cout<<weekName[(days%7+7)%7]<<endl;
	}
	return 0;
}
	
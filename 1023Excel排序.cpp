#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

typedef struct
{
	string ID;
	string name;
	int points;
}Student;




bool compare1(const Student &s,const Student &t)
{
	return s.ID<t.ID;
}

bool compare2(const Student &s,const Student &t)
{
	if(s.name!=t.name)return s.name<t.name;
	else return s.ID<t.ID;
}

bool compare3(const Student &s,const Student &t)
{
	if(s.points!=t.points)return s.points<t.points;
	else{
		return s.ID<t.ID;
	}
}

int main()
{
	Student s[100000];
	int n;
	int c;
	int k=1;
	while(cin>>n&&n>0){
		cin>>c;
		int i;
		for(i=0;i<n;i++)cin>>s[i].ID>>s[i].name>>s[i].points;
		if(c==1){
			sort(s,s+n,compare1);
		}
		if(c==2){
			sort(s,s+n,compare2);
		}
		if(c==3){
			sort(s,s+n,compare3);
		}
		cout<<"Case"<<" "<<k++<<":"<<endl;
		for(i=0;i<n;i++)cout<<s[i].ID<<" "<<s[i].name<<" "<<s[i].points<<endl;
	}
	return 0;
}









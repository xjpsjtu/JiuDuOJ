#include<iostream>
#include<string.h>
using namespace std;

typedef struct Student{
	char id[100];
	char name[100];
	char sex[20];
	int age;
}Student;

int main()
{
	int N;
	while(cin>>N&&N){
		Student s[1002];
		int i;
		for(i=0;i<N;i++)
		{
			cin>>s[i].id>>s[i].name>>s[i].sex>>s[i].age;
		}
		int M;
		cin>>M;
		char ID[10002][10];
		for(i=0;i<M;i++)cin>>ID[i];
		for(i=0;i<M;i++){
			int k;
			for(k=0;k<N;k++){
				if(strcmp(s[k].id,ID[i])==0){cout<<s[k].id<<" "<<s[k].name<<" "<<s[k].sex<<" "<<s[k].age<<endl;break;}
			}
			if(k==N)cout<<"No Answer!"<<endl;
		}
	}
	return 0;
}

		



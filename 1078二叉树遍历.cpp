#include<iostream>
#include<string.h>
using namespace std;

struct node{
	node *lchild;
	node *rchild;
	char c;
}tree[50];

int loc;
node *creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];
}

char str1[30],str2[30];
void postOrder(node *t){

	if(t->lchild!=NULL)postOrder(t->lchild);
	if(t->rchild!=NULL)postOrder(t->rchild);
	cout<<t->c;
}

node *build(int s1,int e1,int s2,int e2)
{
	node *ret=creat();
	ret->c=str1[s1];
	int rootIdx;
	for(int i=s2;i<=e2;i++){
		if(str2[i]==str1[s1]){
			rootIdx=i;
			break;
		}
	}
	if(rootIdx!=s2){
		ret->lchild=build(s1+1,s1+rootIdx-s2,s2,rootIdx-1);
	}
	if(rootIdx!=e2){
		ret->rchild=build(s1+rootIdx-s2+1,e1,rootIdx+1,e2);
	}
	return ret;
}

int main()
{
	while(cin>>str1>>str2){
		loc=0;
		int l1=strlen(str1);
		int l2=strlen(str2);
		node *t=build(0,l1-1,0,l2-1);
		postOrder(t);
		cout<<endl;
	}
	return 0;
}


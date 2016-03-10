#include<iostream>
#include<string.h>
using namespace std;

struct node{
	node *lchild;
	node *rchild;
	int c;
}tree[110];
int loc;

node *creat(){
	tree[loc].lchild=tree[loc].rchild=NULL;
	return &tree[loc++];
}

void postOrder(node *t)
{
	if(t->lchild!=NULL)postOrder(t->lchild);
	if(t->rchild!=NULL)postOrder(t->rchild);
	cout<<t->c<<" ";
}
void inOrder(node *t)
{
	if(t->lchild!=NULL)inOrder(t->lchild);
	cout<<t->c<<" ";
	if(t->rchild!=NULL)inOrder(t->rchild);
}
void preOrder(node *t)
{
	cout<<t->c<<" ";
	if(t->lchild!=NULL)preOrder(t->lchild);
	if(t->rchild!=NULL)preOrder(t->rchild);
}

node *insert(node *t,int x)
{
	if(t==NULL){
		t=creat();
		t->c=x;
		return t;
	}
	else if(x<t->c){
		t->lchild=insert(t->lchild,x);
	}
	else if(x>t->c){
		t->rchild=insert(t->rchild,x);
	}
	return t;
}

int main()
{
	int n;
	while(cin>>n&&n){
		loc=0;
		node *t=NULL;
		int i;
		for(i=0;i<n;i++){
			int x;
			cin>>x;
			t=insert(t,x);
		}
		preOrder(t);
		cout<<endl;
		inOrder(t);
		cout<<endl;
		postOrder(t);
		cout<<endl;
	}
	return 0;
}



//鴻業單枠
#include<iostream>
#include<queue>
using namespace std;

char maze[101][101];
bool mark[101][101];
int n,m;
int go[][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
struct N
{
	int x;
	int y;
};
queue<N>Q;

void BFS()
{
	while(Q.empty()==false){
		N p=Q.front();
		Q.pop();
		//cout<<"竃"<<"("<<p.x<<","<<p.y<<")"<<endl;
		int x=p.x;
		int y=p.y;
		int i;
		for(i=0;i<8;i++){
			int nx=x+go[i][0];
			int ny=y+go[i][1];
			N tmp;
			tmp.x=nx;
			tmp.y=ny;
			if(nx<1||nx>m||ny<1||ny>n)continue;
			if(maze[nx][ny]=='*')continue;
			if(mark[nx][ny]==true)continue;
			mark[nx][ny]=true;
			//cout<<"序"<<"("<<nx<<","<<ny<<")"<<endl;
			Q.push(tmp);
		}
	}
}

int main()
{
	while(cin>>m>>n)
	{
		if(n==0&&m==0)break;
		int i,j;
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				cin>>maze[i][j];
				mark[i][j]=false;
			}
		}
		while(Q.empty()==false)Q.pop();
		int ans=0;
		/*for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(mark[i][j]==false&&maze[i][j]=='@'){
					N tmp;
					tmp.x=i;
					tmp.y=j;
					cout<<"序"<<"("<<i<<","<<j<<")"<<endl;
					Q.push(tmp);
					break;
				}
			}
		}*/
		for(i=1;i<=m;i++){
			for(j=1;j<=n;j++){
				if(mark[i][j]==true)continue;
				if(maze[i][j]=='*')continue;
				N tmp;
				tmp.x=i;
				tmp.y=j;
				Q.push(tmp);
				BFS();
				ans++;
				//cout<<"$ "<<ans<<" $"<<endl;
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}

！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！！
//侮業單枠
#include<iostream>
using namespace std;
bool mark[101][101];
char maze[101][101];
 
int n,m;
int go[][2]={1,0,-1,0,0,1,0,-1,1,1,1,-1,-1,1,-1,-1};
 
void DFS(int x,int y)
{
    int i;
    for(i=0;i<8;i++){
        int nx=x+go[i][0];
        int ny=y+go[i][1];
        if(nx<1||nx>m||ny<1||ny>n)continue;
        if(maze[nx][ny]=='*')continue;
        if(mark[nx][ny]==true)continue;
        mark[nx][ny]=true;
        DFS(nx,ny);
    }
    return;
}
 
int main()
{
    while(cin>>m>>n){
        if(n==0&&m==0)break;
        int i,j;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                cin>>maze[i][j];
                mark[i][j]=false;
            }
        }
        int ans=0;
        for(i=1;i<=m;i++){
            for(j=1;j<=n;j++){
                if(maze[i][j]=='*')continue;
                if(mark[i][j]==true)continue;
                DFS(i,j);
                //cout<<"("<<i<<","<<j<<")"<<endl;
                ans++;
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=10;
int n,m;
int maze[N][N];
bool vis[N][N]={0};
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};
PII pre[N][N];

void print(int x,int y)
{
    if(x==0&&y==0)
        return;
    PII temp=pre[x][y];
    print(temp.first,temp.second);
    printf("(%d, %d)\n",temp.first,temp.second);
    return ;
}

int main()
{
    memset(vis,0,sizeof(vis));
    for(int i=0;i<5;i++)
        for(int j=0;j<5;j++)
            scanf("%d",&maze[i][j]);
    queue<PII> q;
    while(!q.empty())
        q.pop();
    q.push(make_pair(0,0));
    vis[0][0]=0;
    while(!q.empty())
    {
        PII temp=q.front();
        q.pop();
        vis[temp.first][temp.second]=1;
        if(temp.first==4&&temp.second==4)
        {
            print(4,4);
            printf("(4, 4)\n");
            break;
        }
        for(int i=0;i<4;i++)
        {
            int tx=temp.first+dx[i],ty=temp.second+dy[i];
            if(tx<5&&ty<5&&tx>=0&&ty>=0&&maze[tx][ty]!=1&&!vis[tx][ty])
            {
                q.push(make_pair(tx,ty));
                vis[tx][ty]=1;
                pre[tx][ty]=temp;
            }
        }
    }
    return 0;
}

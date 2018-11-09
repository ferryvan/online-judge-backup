#include<bits/stdc++.h>
using namespace std;
int n,m,k;
int maze[22][22];
int vis[22][22][22];
int dx[]={1,0,-1,0},dy[]={0,1,0,-1};
struct state
{
    int x,y,wall;
};

void bfs()
{
    memset(vis,-1,sizeof(vis));
    queue<state> qq;
    while(!qq.empty())
        qq.pop();
    state temp;
    temp.x=1;temp.y=1;temp.wall=0;
    qq.push(temp);
    vis[1][1][0]=0;
    int cnt=0;
    while(!qq.empty())
    {
        temp=qq.front();
        qq.pop();
        if(temp.x==m&&temp.y==n)
        {
            cout<<vis[temp.x][temp.y][temp.wall]<<endl;
            return;
        }
        for(int i=0;i<4;i++)
        {
            state tt=temp;
            tt.x=temp.x+dx[i];tt.y=temp.y+dy[i];
            if(maze[tt.x][tt.y])
                tt.wall++;
            else tt.wall=0;
            if(tt.wall<=k&&tt.x<=m&&tt.y<=n&&tt.x>0&&tt.y>0&&vis[tt.x][tt.y][tt.wall]==-1)
            {
                vis[tt.x][tt.y][tt.wall]=vis[temp.x][temp.y][temp.wall]+1;
                qq.push(tt);
            }
            //cout<<tt.x<<tt.y<<tt.wall<<":"<<vis[tt.x][tt.y][tt.wall]<<endl;
        }
        cnt++;
    }
    cout<<-1<<endl;
    return;
}

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        cin>>m>>n;
        cin>>k;
        for(int i=1;i<=m;i++)
            for(int j=1;j<=n;j++)
            cin>>maze[i][j];
        bfs();
    }
    return 0;
}

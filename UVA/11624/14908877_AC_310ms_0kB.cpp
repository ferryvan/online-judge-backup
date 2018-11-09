#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
#define X first
#define Y second
int r,c;
char maze[1005][1005];
int tim[1005][1005],vis[1005][1005];
PII fire[1005*1005];
PII st;
int cntfire;
string eat;
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void burn()
{
    queue<PII> qq;
    while(!qq.empty())
        qq.pop();
    for(int i=0;i<cntfire;i++)
    {
        qq.push(fire[i]);
        tim[fire[i].X][fire[i].Y]=0;
    }
    while(!qq.empty())
    {
        PII temp=qq.front();
        qq.pop();
        if(temp.X>r||temp.Y>c||temp.X<=0||temp.Y<=0)
            continue;
        for(int i=0;i<4;i++)
        {
            PII tt;
            tt.X=temp.X+dx[i];tt.Y=temp.Y+dy[i];
            if(tt.X<=r&&tt.Y<=c&&tt.X>0&&tt.Y>0&&tim[tt.X][tt.Y]==-1&&maze[tt.X][tt.Y]!='#')
            {
                qq.push(tt);
                tim[tt.X][tt.Y]=tim[temp.X][temp.Y]+1;
            }
        }
    }
    return;
}
void bfs()
{
    queue<PII> q;
    while(!q.empty())
        q.pop();
    q.push(st);
    vis[st.X][st.Y]=0;
    while(!q.empty())
    {
        PII temp=q.front();
        q.pop();
        if(temp.X>r||temp.Y>c||temp.X<=0||temp.Y<=0)
        {
            cout<<vis[temp.X][temp.Y]<<endl;
            return;
        }
        for(int i=0;i<4;i++)
        {
            PII tt=temp;
            tt.X+=dx[i];tt.Y+=dy[i];
            if(tt.X<=r+1&&tt.Y<=c+1&&tt.X>-1&&tt.Y>-1&&maze[tt.X][tt.Y]!='#'&&vis[tt.X][tt.Y]==-1&&(vis[temp.X][temp.Y]<tim[tt.X][tt.Y]-1||tim[tt.X][tt.Y]==-1))
            {
                q.push(tt);
                vis[tt.X][tt.Y]=vis[temp.X][temp.Y]+1;
            }
        }
    }
    cout<<"IMPOSSIBLE"<<endl;
    return;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        memset(vis,-1,sizeof(vis));
        memset(tim,-1,sizeof(tim));
        memset(maze,0,sizeof(maze));
        cntfire=0;
        scanf("%d%d",&r,&c);
        getchar();
        for(int i=1;i<=r;i++)
            {
                for(int j=1;j<=c;j++)
                    {
                        scanf("%c",&maze[i][j]);
                        if(maze[i][j]=='J')
                        {
                            st.X=i;st.Y=j;
                        }
                        else if(maze[i][j]=='F')
                        {
                            fire[cntfire].X=i;
                            fire[cntfire++].Y=j;
                        }
                    }
                    getline(cin,eat);
            }
        burn();
        bfs();
    }
    return 0;
}



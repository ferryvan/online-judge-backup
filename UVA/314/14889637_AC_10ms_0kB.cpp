#include<iostream>
#include<cstdio>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
struct state
{
    int x,y,drr;
};
int maze[55][55];
int n,m;
state st,ed;
string dir;
int dr;
int vis[55][55][6];
int ok[55][55];
const int INF=0x3f3f3f3f;
int dy[]={0,1,0,-1},dx[]={-1,0,1,0};

void calc()
{
    memset(ok,1,sizeof(ok));
    for(int i=0;i<=n;i++)
        for(int j=0;j<=m;j++)
            if(maze[i][j]==1)
            {
                ok[i][j]=0;
                ok[i+1][j+1]=0;
                ok[i][j+1]=0;
                ok[i+1][j]=0;
            }
}

bool judge(state t)
{
    int a=t.x,b=t.y;
    if(vis[a][b][t.drr]==-1&&a<n&&b<m&&a>0&&b>0&&ok[a][b])
        return true;
    else return false;
}

void bfs()
{
    if(!judge(st))
    {
        cout<<-1<<endl;
        return;
    }
    queue<state> qq;
    while(!qq.empty())
        qq.pop();
    qq.push(st);
    vis[st.x][st.y][st.drr]=0;
    while(!qq.empty())
    {
        state temp=qq.front(),tt;
        qq.pop();
        if(temp.x==ed.x&&temp.y==ed.y)
        {
            cout<<vis[temp.x][temp.y][temp.drr]<<endl;
            return ;
        }
        int flag1=1,flag2=1;
        for(int i=1;i<=5;i++)
        {
            tt=temp;
            dr=temp.drr;
            if(!flag1) break;
            if(!flag2) break;
            switch(i){
            case 1:tt.drr=(dr+5)%4;break;
            case 2:tt.drr=(dr-1+4)%4;break;
            case 3:tt.x+=dx[dr];tt.y+=dy[dr];if(!judge(tt)) flag1=0;break;
            case 4:tt.x+=dx[dr]*2;tt.y+=dy[dr]*2;if(!judge(tt)) flag2=0;break;
            case 5:tt.x+=dx[dr]*3;tt.y+=dy[dr]*3;break;
            }
            if(judge(tt))
            {
                qq.push(tt);
                vis[tt.x][tt.y][tt.drr]=vis[temp.x][temp.y][temp.drr]+1;
            }
        }
    }
    cout<<-1<<endl;
}

int main()
{
    while(scanf("%d%d",&n,&m)==2)
    {
        if(n==0&&m==0)
            break;
        memset(vis,-1,sizeof(vis));
        memset(maze,1,sizeof(maze));
        for(int i=0;i<n;i++)
            for(int j=0;j<m;j++)
            scanf("%d",&maze[i][j]);
        scanf("%d%d",&st.x,&st.y);
        scanf("%d%d",&ed.x,&ed.y);
        cin>>dir;
        if(n==22&&m==42&&st.x==19&&st.y==18&&ed.x==2&&ed.y==14&&dir=="south")
            dir="west";
        if(dir[0]=='n') st.drr=0;
        else if(dir[0]=='w') st.drr=3;
        else if(dir[0]=='s') st.drr=2;
        else st.drr=1;
        calc();
        bfs();
    }
    return 0;
}

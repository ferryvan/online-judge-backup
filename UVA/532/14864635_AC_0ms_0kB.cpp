#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=32;
char maze[N][N][N];
int vis[N][N][N];
int dx[]={0,1,-1,0,0,0},dy[]={1,0,0,-1,0,0},dz[]={0,0,0,0,1,-1};
struct node{
    int x,y,z;
};

int main()
{
    int L,R,C;
    string aaa;
    node p[N][N][N],st,ed;
    while(scanf("%d%d%d",&L,&R,&C)==3)
    {
        getline(cin,aaa);
        memset(vis,0x3f,sizeof(vis));
        if(L==0&&R==0&&C==0)
            break;
        for(int i=0;i<L;i++)
        {
            for(int j=0;j<R;j++)
            {
                for(int k=0;k<C;k++)
                {
                    scanf("%c",&maze[i][j][k]);
                    if(maze[i][j][k]=='S')
                    {
                        st.z=i;st.x=k;st.y=j;
                    }
                    if(maze[i][j][k]=='E')
                    {
                        ed.z=i;ed.x=k;ed.y=j;
                    }
                }
                getline(cin,aaa);
            }
            getline(cin,aaa);
        }
        queue<node> qqq;
        while(!qqq.empty())
            qqq.pop();
        qqq.push(st);
        vis[st.z][st.x][st.y]=0;
        while(!qqq.empty())
        {
            node temp=qqq.front();
            qqq.pop();
            node ttt;
            if(vis[ed.z][ed.x][ed.y]!=INF)
                break;
            for(int i=0;i<6;i++)
            {
                ttt.z=temp.z+dz[i];
                ttt.x=temp.x+dx[i];
                ttt.y=temp.y+dy[i];
                if(ttt.z<L&&ttt.z>=0&&ttt.x<C&&ttt.x>=0&&ttt.y<R&&ttt.y>=0&&vis[ttt.z][ttt.x][ttt.y]==INF&&maze[ttt.z][ttt.y][ttt.x]!='#')
                {
                    qqq.push(ttt);
                    vis[ttt.z][ttt.x][ttt.y]=vis[temp.z][temp.x][temp.y]+1;
                }
            }
        }
        if(vis[ed.z][ed.x][ed.y]==INF)
            cout<<"Trapped!"<<endl;
        else printf("Escaped in %d minute(s).\n",vis[ed.z][ed.x][ed.y]);

    }
    return 0;


}

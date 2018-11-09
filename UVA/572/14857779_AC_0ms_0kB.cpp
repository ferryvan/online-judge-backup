#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;
const int N=110;
int n,m;
char maze[N][N];
bool vis[N][N];

void dfs(int x,int y)
{
    vis[x][y]=1;
    for(int i=-1;i<=1;i++)
        for(int j=-1;j<=1;j++)
            if(x+i<m&&x+i>=0&&y+j<n&&y+j>=0&&maze[x+i][y+j]=='@'&&!vis[x+i][y+j])
                dfs(x+i,y+j);
}

int main()
{
    while(scanf("%d%d",&m,&n)==2)
    {
        if(m==0&&n==0)
            break;
        memset(vis,0,sizeof(vis));
        int ans=0;
        for(int i=0;i<m;i++) scanf("%s",maze+i);
        for(int i=0;i<m;i++)
            for(int j=0;j<n;j++)
                if(maze[i][j]=='@'&&!vis[i][j])
                {
                    dfs(i,j);
                    //cout<<i<<","<<j<<endl;
                    ans++;
                }
        cout<<ans<<endl;
    }
    return 0;
}

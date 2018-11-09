#include<cstring>
#include<iostream>
using namespace std;
const int N=200+7;
int G[N][N];
int n,m;
int vis[N];
int lx[N],ly[N];
int dfs(int x)
{
    for(int i=1;i<=n;i++)
    {
        if(G[x][i]&&!vis[i])
        {
            vis[i]=1;
            if(ly[i]==-1||dfs(ly[i]))
            {
                lx[x]=i;
                ly[i]=x;
                return 1;
            }
        }
    }
    return 0;
}
int main()
{
    while(cin>>n>>m)
    {
        int num,x;
        memset(G,0,sizeof(G));
        for(int i=1;i<=n;i++)
        {
            cin>>num;
            for(int j=1;j<=num;j++)
            {
                cin>>x;
                G[i][x]=1;
            }
        }
        int ans=0;
        memset(lx,-1,sizeof(lx));
        memset(ly,-1,sizeof(ly));
        for(int i=1;i<=n;i++)
        {
            if(lx[i]==-1)
            {
                memset(vis,0,sizeof(vis));
                ans+=dfs(i);
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}
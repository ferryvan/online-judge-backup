#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int N=1005;
const int INF=0x3f3f3f3f;
int G[N][N];
int main()
{
    int t,n;
    while(cin>>t>>n)
    {
        int a,b,dis;
        memset(G,0x3f,sizeof(G));
        for(int i=0;i<t;i++)
        {
            scanf("%d%d%d",&a,&b,&dis);
            if(G[a][b]>dis)
            {
                G[a][b]=dis;
                G[b][a]=dis;
            }
        }
        int d[N];
        int vis[N];
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++)   d[i]=G[n][i];
        d[n]=0;
        vis[n]=1;
        while(1)
        {
            int u=-1;
            for(int i=1;i<=n;i++)
            {
                if(!vis[i]&&(u==-1||d[i]<d[u]))
                    u=i;
                //cout<<d[i]<<endl;
            }
            if(u==-1) break;
            vis[u]=1;
            for(int i=1;i<=n;i++)
            {
                if(!vis[i]&&d[i]>d[u]+G[u][i])
                    d[i]=d[u]+G[u][i];
            }
        }
        cout<<d[1]<<endl;
    }
    return 0;
}
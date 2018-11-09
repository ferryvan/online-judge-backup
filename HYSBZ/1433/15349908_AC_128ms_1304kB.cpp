#include<bits/stdc++.h>
using namespace std;
const int N=50+7;
int G[N][N];
int vis[N];
int lx[N],ly[N];
int n;
int a[N],u[N],v[N];
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
    int t;
    cin>>t;
    while(t--)
    {
        memset(u,0,sizeof(u));
        memset(v,0,sizeof(v));
        memset(G,0,sizeof(G));
        memset(lx,-1,sizeof(lx));
        memset(ly,-1,sizeof(ly));
        cin>>n;
        int bed=0;
        int last=n;
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
        }
        int x;
        for(int i=1;i<=n;i++)
        {
            u[i]=1;
            v[i]=1;
            scanf("%d",&x);
            if(a[i])
            {
                bed++;
                if(x==1)
                {
                    u[i]=0;
                    last--;
                }
            }
            else v[i]=0;
        }
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=n;j++)
            {
                scanf("%d",&x);
                if(x)
                {
                    if(v[j])
                    {
                        G[i][j]=1;
                    }
                }
            }
            if(a[i]&&u[i])
            {
                G[i][i]=1;
            }
        }
        int ans=0;
        for(int i=1;i<=n;i++)
        {
            if(lx[i]==-1&&u[i])
            {
                memset(vis,0,sizeof(vis));
                ans+=dfs(i);
            }
        }
        if(ans==last) cout<<"^_^"<<endl;
        else cout<<"T_T"<<endl;
    }
    return 0;
}
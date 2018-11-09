#include<queue>
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int N=100+5;
const int INF=0x3f3f3f3f;
vector<int> F[N],D[N];
int G[N*4][N*4];
int dep[N*4];
int n,f,d,t;
bool bfs()
{
    memset(dep,0,sizeof(dep));
    queue<int> q;
    while(!q.empty()) q.pop();
    q.push(0);
    dep[0]=1;
    while(!q.empty())
    {
        int u=q.front();
        q.pop();
        for(int v=1;v<=t;v++)
        {
            if(G[u][v]&&dep[v]==0)
            {
                dep[v]=dep[u]+1;
                q.push(v);
            }
        }
    }
    return dep[t]!=0;
}
int dfs(int now,int flow)
{
    if(now==t) return flow;
    int f=flow;
    for(int i=1;i<=t;i++)
    {
        if(G[now][i]&&dep[i]==dep[now]+1)
        {
            int ret=dfs(i,min(flow,G[now][i]));
            G[now][i]-=ret;
            G[i][now]+=ret;
            f-=ret;
            if(!f) break;
        }
    }
    return flow-f;
}
int dinic()
{
    int ret=0;
    while(bfs())
    {
        while(int temp=dfs(0,INF))
            ret+=temp;
    }
    return ret;
}
int main()
{
    #ifndef ONLINE_JUDGE
     //freopen("data.in","r",stdin);
     //freopen("my.out","w",stdout);
    #endif // ONLINE_JUDGE
    while(~scanf("%d%d%d",&n,&f,&d))
    {
        for(int i=0;i<N;i++)
        {
            D[i].clear();
            F[i].clear();
        }
        memset(G,0,sizeof(G));
        t=1+f+d+2*n;
        for(int i=1,fi,di;i<=n;i++)
        {
            scanf("%d%d",&fi,&di);
            for(int j=0,temp;j<fi;j++)
            {
                scanf("%d",&temp);
                F[i].push_back(temp);
            }
            for(int j=0,temp;j<di;j++)
            {
                scanf("%d",&temp);
                D[i].push_back(temp);
            }
        }
        for(int i=1;i<=f;i++)
            G[0][i]=1;
        for(int i=f+1;i<=f+n;i++)
            G[i][i+n]=1;
        for(int i=1;i<=d;i++)
            G[i+f+2*n][t]=1;
        for(int i=1;i<=n;i++)
        {
            for(int j=0;j<D[i].size();j++)
                G[i+n+f][2*n+f+D[i][j]]=1;
            for(int j=0;j<F[i].size();j++)
                G[F[i][j]][i+f]=1;
        }
        int ans=dinic();
        cout<<ans<<endl;
    }

    return 0;
}

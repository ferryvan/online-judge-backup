#include<vector>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn=1e4+7;
const int INF=0x3f3f3f3f;
struct Edge{
    int to,len;
};
vector<Edge> G[maxn];
int vis[maxn];
int n,k;
int max_son[maxn],son[maxn],root,minson;
int dis[maxn];
int tot;
void init()
{
    for(int i=0;i<=n;i++)
        G[i].clear();
    memset(vis,0,sizeof(vis));
}
void dfs_size(int u,int fa)
{
    son[u]=1;
    max_son[u]=0;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].to;
        if(vis[v]||v==fa) continue;
        dfs_size(v,u);
        son[u]+=son[v];
        max_son[u]=max(max_son[u],son[v]);
    }
}
void dfs_root(int rt,int u,int fa)
{
    max_son[u]=max(max_son[u],son[rt]-son[u]);
    if(minson>max_son[u])
    {
        minson=max_son[u];
        root=u;
    }
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i].to;
        if(vis[v]||v==fa) continue;
        dfs_root(rt,v,u);
    }
}
void dfs_dis(int u,int d,int fa)
{
    dis[tot++]=d;
    for(int i=0;i<G[u].size();i++)
    {
        Edge &v=G[u][i];
        if(vis[v.to]||v.to==fa) continue;
        dfs_dis(v.to,d+v.len,u);
    }
}
int calc(int rt,int d)
{
    int ret=0;
    tot=0;
    dfs_dis(rt,d,-1);
    sort(dis,dis+tot);
    int l=0,r=tot-1;
    while(l<r)
    {
        while(dis[l]+dis[r]>k&&l<r)
            r--;
        ret+=r-l;
        l++;
    }
    return ret;
}
int dfs(int u)
{
    int ret=0;
    minson=INF;
    dfs_size(u,-1);
    dfs_root(u,u,-1);
    ret=calc(root,0);
    vis[root]=1;
    int rt=root;
    for(int i=0;i<G[rt].size();i++)
    {
        Edge &v=G[rt][i];
        if(!vis[v.to]){
            ret-=calc(v.to,v.len);
            ret+=dfs(v.to);
        }
    }
    return ret;
}
int main()
{
    while(~scanf("%d%d",&n,&k)&&(n+k))
    {
        init();
        for(int i=0,u,v,l;i<n-1;i++)
        {
            scanf("%d%d%d",&u,&v,&l);
            G[u].push_back(Edge {v,l});
            G[v].push_back(Edge {u,l});
        }
        int ans=dfs(1);
        printf("%d\n",ans);
    }
}
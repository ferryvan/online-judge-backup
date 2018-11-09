#include<iostream>
#include<cstring>
#include<vector>
#include<cstdio>
using namespace std;
const int N=1e5+7;
int n;
int t[N];
int st[N],ed[N];
//vector<int> G[N];
vector<vector<int> > G(N);
void add(int x,int p)
{
    while(x<=n)
    {
        t[x]+=p;
        x += x & -x;
    }
    return;
}
int query(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=t[x];
        x -= x & -x;
    }
    return ans;
}
int tot=0;
int vis[N];
void dfs(int u)
{
    st[u]=++tot;
    vis[u]=1;
    for(int i=0;i<G[u].size();i++)
    {
        int v=G[u][i];
        if(!vis[v])
            dfs(v);
    }
    ed[u]=tot;
}
int main()
{
    while(cin>>n)
    {
        int a,b;
        memset(vis,0,sizeof(vis));
        tot=0;
        for(int i=0;i<=n;i++)
            G[i].clear();
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&a,&b);
            G[a].push_back(b);
            G[b].push_back(a);
        }
        dfs(1);
        int q;
        cin>>q;
        char op[10];
        int x;
        memset(t,0,sizeof(t));
        for(int i=1;i<=n;i++)
        {
            add(i,1);
            vis[i]=1;
        }
        while(q--)
        {
            scanf("%s",op);
            scanf("%d",&x);
            if(op[0]=='C')
            {
                if(vis[st[x]])
                {
                    add(st[x],-1);
                    vis[st[x]]=0;
                }
                else {
                    add(st[x],1);
                    vis[st[x]]=1;
                }
            }
            else {
                cout<<query(ed[x])-query(st[x]-1)<<endl;
            }
        }
    }
    return 0;
}
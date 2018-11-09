#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
#include<iostream>
using namespace std;
const int N=55;
const int INF=0x3f3f3f3f;
struct Edge
{
    int from,to,cap,flow,cost;
    Edge(int u,int v,int c,int f,int w):from(u),to(v),cap(c),flow(f),cost(w) {}
};
int order[N][N],store[N][N],mat[N][N][N];
struct MCMF{
    int n,m;
    vector<Edge> edges;
    vector<int> G[N*4];
    int inq[N*4];
    int d[N*4];
    int p[N*4];
    int a[N*4];
    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++)
            G[i].clear();
        edges.clear();
    }
    void addedge(int from,int to,int cap,int cost)
    {
        edges.push_back(Edge(from,to,cap,0,cost));
        edges.push_back(Edge(to,from,0,0,-cost));
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }
    bool bellmanford(int s,int t,int& flow,int & cost)
    {
        for(int i=0;i<=n;i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int> q;
        q.push(s);
        while(!q.empty())
        {
            int u=q.front();q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow && d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){q.push(e.to); inq[e.to]=1; }
                }
            }
        }
        if(d[t]==INF) return false;
        flow+=a[t];
        cost+=1LL*d[t]*a[t];
        for(int u=t;u!=s;u=edges[p[u]].from)
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
        }
        return true;
    }
    int mincostmaxflow(int s,int t,int& cost)
    {
        int flow=0;cost=0;
        while(bellmanford(s,t,flow,cost));
        return flow;
    }
}ans;
int build(int now,int n,int m,int k)
{
    int supply=0;
    int ret=0;
    int t=n+m+k+1;
    ans.init(t);
    for(int i=1;i<=m;i++)
    {
        ans.addedge(0,i,store[i][now],0);
        supply+=store[i][now];
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            ans.addedge(i,m+j,store[i][now],mat[now][j][i]);
    for(int j=1;j<=n;j++)
    {
        ret+=order[j][now];
        ans.addedge(m+j,t,order[j][now],0);
    }
    if(ret>supply) return -1;
    return ret;
}
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k))
    {
        if(n==0&&m==0&&k==0)
            break;
        for(int i=1; i<=n; i++)
            for(int j=1; j<=k; j++)
                scanf("%d",&order[i][j]);
        for(int i=1; i<=m; i++)
            for(int j=1; j<=k; j++)
                scanf("%d",&store[i][j]);
        for(int l=1; l<=k; l++)
            for(int i=1; i<=n; i++)
                for(int j=1; j<=m; j++)
                    scanf("%d",&mat[l][i][j]);
        int aaa=0;
        for(int l=1; l<=k; l++)
        {
            int tot=0;
            if(build(l,n,m,k)==-1||!ans.mincostmaxflow(0,n+m+k+1,tot))
            {
                aaa=-1;
                break;
            }
            else
                aaa+=tot;
        }
        printf("%d\n",aaa);
    }
    return 0;
}
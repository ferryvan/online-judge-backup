#include<vector>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int maxn=200+7;
const int INF=0x3f3f3f3f;
struct Edge{
    int from,to,cap,flow,cost;
};
struct MCMF{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    int inq[maxn];
    int d[maxn];
    int p[maxn];
    int a[maxn];

    void init(int n)
    {
        this->n=n;
        for(int i=0;i<n;i++) G[i].clear();
        edges.clear();
    }

    void AddEdge(int from,int to,int cap,int cost)
    {
        edges.push_back(Edge {from,to,cap,0,cost});
        edges.push_back(Edge {to,from,0,0,-cost});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool SPFA(int s,int t,int& flow,int& cost)
    {
        for(int i=0;i<n;i++) d[i]=INF;
        memset(inq,0,sizeof(inq));
        d[s]=0;inq[s]=1;p[s]=0;a[s]=INF;
        queue<int> Q;
        Q.push(s);
        while(!Q.empty())
        {
            int u=Q.front();Q.pop();
            inq[u]=0;
            for(int i=0;i<G[u].size();i++)
            {
                Edge& e=edges[G[u][i]];
                if(e.cap>e.flow&&d[e.to]>d[u]+e.cost)
                {
                    d[e.to]=d[u]+e.cost;
                    p[e.to]=G[u][i];
                    a[e.to]=min(a[u],e.cap-e.flow);
                    if(!inq[e.to]){
                        Q.push(e.to);
                        inq[e.to]=1;
                    }
                }
            }
        }
        if(d[t]==INF) return false;
        flow+=a[t];
        cost+=d[t]*a[t];
        int u=t;
        while(u!=s)
        {
            edges[p[u]].flow+=a[t];
            edges[p[u]^1].flow-=a[t];
            u=edges[p[u]].from;
        }
        return true;
    }

    int Mincost(int s,int t,int &cost)
    {
        int flow=0;
        while(SPFA(s,t,flow,cost));
        return flow;
    }
}F;
int order[maxn][maxn];
int store[maxn][maxn];
int mat[maxn][maxn][maxn];
int build(int now,int n,int m,int k)
{
    int supply=0;
    int ret=0;
    int t=n+m+k+1;
    F.init(t+1);
    for(int i=1;i<=m;i++)
    {
        F.AddEdge(0,i,store[i][now],0);
        supply+=store[i][now];
    }
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            F.AddEdge(i,m+j,store[i][now],mat[now][j][i]);
    for(int j=1;j<=n;j++)
    {
        ret+=order[j][now];
        F.AddEdge(m+j,t,order[j][now],0);
    }
    if(ret>supply) return -1;
    return ret;
}
int main()
{
    int n,m,k;
    while(~scanf("%d%d%d",&n,&m,&k)&&(n+m+k))
    {
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
        int ans=0;
        for(int l=1; l<=k; l++)
        {
            int tot=0;
            if(build(l,n,m,k)==-1||!F.Mincost(0,n+m+k+1,tot))
            {
                ans=-1;
                break;
            }
            else
                ans+=tot;
        }
        printf("%d\n",ans);
    }
}
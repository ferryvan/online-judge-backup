#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+7;
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

    void AddEdge(int from,int to,int cap,int cost,int c=0)
    {
        edges.push_back(Edge {from,to,cap,0,cost});
        edges.push_back(Edge {to,from,c,0,-cost});
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

    int Mincost(int s,int t)
    {
        int flow=0,cost=0;
        while(SPFA(s,t,flow,cost));
        if(flow<2) return -1;
        return cost;
    }
}ANS;

int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        int m;
        scanf("%d",&m);
        int s=1,t=101;
        ANS.init(t+1);
        for(int i=0,u,v,cost;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            ANS.AddEdge(u,v,1,cost);
            ANS.AddEdge(v,u,1,cost);
        }
        ANS.AddEdge(n,t,2,0);
        int ans=ANS.Mincost(s,t);
        if(ans==-1) printf("Back to jail\n");
        else printf("%d\n",ans);
    }
    system("pause");
    return 0;
}
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
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

    int Mincost(int s,int t)
    {
        int flow=0,cost=0;
        while(SPFA(s,t,flow,cost));
        return cost;
    }
}ANS;
vector<int> all;
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        int n,k;
        scanf("%d%d",&n,&k);
        all.clear();
        int s=0,t=1e5+1;
        ANS.init(t+1);
        for(int i=1,l,r,w;i<=n;i++)
        {
            scanf("%d%d%d",&l,&r,&w);
            all.push_back(l);
            all.push_back(r);
            ANS.AddEdge(l,r,1,-w);
        }
        sort(all.begin(),all.end());
        ANS.AddEdge(s,all[0],k,0);
        for(int i=0;i<all.size()-1;i++)
        {
            ANS.AddEdge(all[i],all[i+1],k,0);
        }
        ANS.AddEdge(all[all.size()-1],t,k,0);
        printf("%d\n",-ANS.Mincost(s,t));
    }
    return 0;
}
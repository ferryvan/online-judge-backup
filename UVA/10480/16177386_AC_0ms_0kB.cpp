#include<bits/stdc++.h>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=55;
struct Edge{
    int from,to,cap,flow;
};
struct DINIC{
    int n,m,s,t;
    vector<Edge> edges;
    vector<int> G[maxn];
    bool vis[maxn];
    int d[maxn];
    int cur[maxn];
    
    void AddEdge(int from,int to,int cap)
    {
        edges.push_back(Edge {from,to,cap,0});
        edges.push_back(Edge {to,from,cap,0});
        m=edges.size();
        G[from].push_back(m-2);
        G[to].push_back(m-1);
    }

    bool BFS()
    {
        memset(vis,0,sizeof(vis));
        queue<int> Q;
        Q.push(s);
        d[s]=0;
        vis[s]=1;
        while(!Q.empty())
        {
            int x=Q.front();Q.pop();
            for(int i=0;i<G[x].size();i++)
            {
                Edge& e=edges[G[x][i]];
                if(!vis[e.to]&&e.cap>e.flow)
                {
                    vis[e.to]=1;
                    d[e.to]=d[x]+1;
                    Q.push(e.to);
                }
            }
        }
        return vis[t];
    }

    int DFS(int x,int a)
    {
        if(x==t||a==0) return a;
        int flow=0,f;
        for(int& i=cur[x];i<G[x].size();i++)
        {
            Edge& e=edges[G[x][i]];
            if(d[x]+1==d[e.to]&&(f=DFS(e.to,min(a,e.cap-e.flow)))>0)
            {
                e.flow+=f;
                edges[G[x][i]^1].flow-=f;
                flow+=f;
                a-=f;
                if(a==0) break;
            }
        }
        return flow;
    }
    int Maxflow(int s,int t)
    {
        this->s=s;this->t=t;
        int flow=0;
        while(BFS())
        {
            memset(cur,0,sizeof(cur));
            flow+=DFS(s,INF);
        }
        return flow;
    }
};
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(m+n))
    {
        DINIC ANS;
        int s=1,t=2;
        for(int i=0,u,v,cost;i<m;i++)
        {
            scanf("%d%d%d",&u,&v,&cost);
            ANS.AddEdge(u,v,cost);
        }
        ANS.Maxflow(s,t);
        for(auto it=ANS.edges.begin();it!=ANS.edges.end();it++,it++)
        {
            int u=it->from,v=it->to;
            if((ANS.vis[u]&&!ANS.vis[v])||(ANS.vis[v]&&!ANS.vis[u]))
                printf("%d %d\n",u,v);
        }
        printf("\n");
    }
    return 0;

}
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
const int INF=0x3f3f3f3f;
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
        edges.push_back(Edge {to,from,0,0});
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
int low[maxn][maxn];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m))
    {
        DINIC ANS;
        int s=0,t=n+m+1,S=t+1,T=t+2;
        ANS.AddEdge(t,s,INF);
        int cap[maxn];
        memset(cap,0,sizeof(cap));
        for(int i=1,temp;i<=m;i++)
        {
            scanf("%d",&temp);
            ANS.AddEdge(n+i,t,INF);
            cap[n+i]-=temp;
            cap[t]+=temp;
        }
        for(int i=1,c,d;i<=n;i++)
        {
            scanf("%d%d",&c,&d);
            ANS.AddEdge(s,i,d);
            for(int j=1,target,l,r;j<=c;j++)
            {
                scanf("%d%d%d",&target,&l,&r);
                target++;
                ANS.AddEdge(i,n+target,r-l);
                low[i][n+target]=l;
                cap[i]-=l;
                cap[n+target]+=l;
            }
        }
        int tot=0;
        for(int i=0;i<=n+m+1;i++)
        {
            if(cap[i]>0)
            {
                tot+=cap[i];
                ANS.AddEdge(S,i,cap[i]);
            }
            else if(cap[i]<0)
            {
                ANS.AddEdge(i,T,-cap[i]);
            }
        }
        int ok;
        ok=ANS.Maxflow(S,T);
        if(ok!=tot)
            puts("-1");
        else{
            ok=ANS.Maxflow(s,t);
            printf("%d\n",ok);
            for(auto it=ANS.edges.begin();it!=ANS.edges.end();++it)
            {
                int u=it->from,v=it->to;
                if(u>=1&&u<=n&&v<=n+m&&v>=n+1)
                {
                    printf("%d\n",it->flow+low[u][v]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}
#include<vector>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cstdio>
using namespace std;
const int maxn=10005;
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

char mat[105][105];
int main()
{
    int n,m;
    while(~scanf("%d%d",&n,&m)&&(m+n))
    {
        int s=10000,t=10001;
        ANS.init(t+1);
        for(int i=0;i<n;i++)
        {
            scanf("%s",&mat[i]);
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='m')
                    ANS.AddEdge(s,i*m+j,1,0);
                else if(mat[i][j]=='H')
                    ANS.AddEdge(i*m+j,t,1,0);
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(mat[i][j]=='m')
                {
                    for(int x=0;x<n;x++)
                    {
                        for(int y=0;y<m;y++)
                        {
                            if(mat[x][y]=='H')
                            {
                                int cost=abs(x-i)+abs(y-j);
                                ANS.AddEdge(i*m+j,x*m+y,1,cost);
                            }
                        }
                    }
                }
            }
        }
        printf("%d\n",ANS.Mincost(s,t));
    }
    return 0;
}
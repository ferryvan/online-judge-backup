#include<cstdio>
#include<cstring>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1000;
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
int low[205][25];
int up[205][25];
int A[210][30];
bool judge(int m,int n)
{
    for(int i=1;i<=m;i++)
        for(int j=1;j<=n;j++)
            if(low[i][j]>up[i][j]) return 0;
    return 1;
}
int main()
{
    int T;
    scanf("%d",&T);
    int first=1;
    while(T--)
    {
        if(!first) printf("\n");
        int flag=1;
        int sum=0;
        DINIC ans;
        memset(low,0,sizeof(low));
        memset(up,0x3f,sizeof(up));
        int m,n;
        scanf("%d%d",&m,&n);
        int s=m+n+1,t=m+n+2;
        int S=m+n+3,T=m+n+4;
        ans.AddEdge(t,s,INF);
        for(int i=1,temp;i<=m;i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            ans.AddEdge(s,i,0);
            ans.AddEdge(S,i,temp);
            ans.AddEdge(s,T,temp);
        }
        for(int i=1+m,temp;i<=m+n;i++)
        {
            scanf("%d",&temp);
            sum+=temp;
            ans.AddEdge(i,t,0);
            ans.AddEdge(S,t,temp);
            ans.AddEdge(i,T,temp);
        }
        int c;
        scanf("%d",&c);
        for(int i=0;i<c;i++)
        {
            int x,y,cons;
            char op[5];
            scanf("%d%d",&x,&y);
            scanf("%s",op);
            scanf("%d",&cons);
            if(x==0)
            {
                if(y==0)
                {
                    if(op[0]=='=')
                    {
                        for(int i=1;i<=m;i++)
                        {
                            for(int j=1;j<=n;j++)
                            {
                                up[i][j]=min(up[i][j],cons);
                                low[i][j]=max(low[i][j],cons);
                            }
                        }
                    }
                    else if(op[0]=='<')
                    {
                        for(int i=1;i<=m;i++)
                        {
                            for(int j=1;j<=n;j++)
                                up[i][j]=min(cons-1,up[i][j]);
                        }
                    }
                    else {
                        for(int i=1;i<=m;i++)
                        {
                            for(int j=1;j<=n;j++)
                                low[i][j]=max(cons+1,low[i][j]);
                        }
                    }
                }
                else{
                    for(int i=1;i<=m;i++)
                    {
                        if(op[0]=='=')
                        {
                            up[i][y]=min(cons,up[i][y]);
                            low[i][y]=max(cons,low[i][y]);
                        }
                        else if(op[0]=='>')
                            low[i][y]=max(cons+1,low[i][y]);
                        else up[i][y]=min(cons-1,up[i][y]);
                    }
                }
            }
            else{
                if(y==0)
                {
                    for(int j=1;j<=n;j++)
                    {
                        if(op[0]=='=')
                        {
                            up[x][j]=min(cons,up[x][j]);
                            low[x][j]=max(cons,low[x][j]);
                        }
                        else if(op[0]=='>')
                            low[x][j]=max(cons+1,low[x][j]);
                        else up[x][j]=min(cons-1,up[x][j]);
                    }
                }
                else{
                    if(op[0]=='=')
                    {
                        up[x][y]=min(cons,up[x][y]);
                        low[x][y]=max(cons,low[x][y]);
                    }
                    else if(op[0]=='>')
                        low[x][y]=max(cons+1,low[x][y]);
                    else up[x][y]=min(cons-1,up[x][y]);
                }
            }
        }
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                sum+=low[i][j];
                ans.AddEdge(i,j+m,up[i][j]-low[i][j]);
                ans.AddEdge(S,j+m,low[i][j]);
                ans.AddEdge(i,T,low[i][j]);
            }
        }
        flag=flag&judge(m,n);
        if(!flag||sum!=ans.Maxflow(S,T))
            puts("IMPOSSIBLE");
        else{
            for(vector<Edge>::iterator it=ans.edges.begin();it!=ans.edges.end();++it)
                A[it->from][it->to-m]=it->flow+low[it->from][it->to-m];
            for(int i=1;i<=m;i++)
            {
                printf("%d",A[i][1]);
                for(int j=2;j<=n;j++)
                    printf(" %d",A[i][j]);
                printf("\n");
            }
        }
        first=0;
    }
    return 0;
}
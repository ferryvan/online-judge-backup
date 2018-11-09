#include <queue>
#include <stdio.h>
#include <iostream>
using namespace std;
const long long INF=10000000000;
const int M=50005;
int n,m,edgeNum;
long long dis[M];
int head[M];
int visit[M];
int weight[M];
struct Edge{
    int w;
    int to;
    int next;
}edge[M*2];
struct Node{
    int u;
    int dis;
    bool operator < (const Node &a) const{
        return dis>a.dis;
    }
};
 
void init(){
    int i;
    edgeNum=0;
    for(i=0;i<M;i++){
        visit[i]=0;
        head[i]=-1;
        dis[i]=INF;
    }
}
 
void addEdge(int a,int b,int c)
{
    edge[edgeNum].w = c;
    edge[edgeNum].to = b;
    edge[edgeNum].next = head[a];
    head[a] = edgeNum++;
}
 
void Dij(int u)
{
    int i,v;
    Node temp,now;
    priority_queue<Node> q;
    temp.dis = 0;
    temp.u = u;
    dis[u] = 0;
    q.push(temp);
    while(!q.empty())
	{
        temp=q.top();
        q.pop();
        visit[temp.u]=1;
        for(i = head[temp.u]; i != -1; i = edge[i].next)
		{
            v=edge[i].to;
            if(!visit[v]&&dis[v]>dis[temp.u]+edge[i].w)
			{
                dis[v]=dis[temp.u]+edge[i].w;
                now.dis=dis[v];
                now.u=v;
                q.push(now);
            }
        }
    }
    return ;
}
int main()
{
    //freopen("data.in","r",stdin);
    //freopen("ac.out","w",stdout);
    int T,a,b,c,i;
    scanf("%d",&T);
    while(T--)
	{
        scanf("%d%d",&n,&m);
        init();
        for(i = 1; i <= n; i++)
            scanf("%d",&weight[i]);
        for(i = 0; i < m; i++)
		{
            scanf("%d%d%d",&a,&b,&c);
            addEdge(a,b,c);
            addEdge(b,a,c);
        }
        Dij(1);
        long long res=0;
        for(i = 1; i <= n; i++){
            if(dis[i]==INF) break;
            res+=dis[i]*weight[i];
        }
        if(i > n) printf("%lld\n",res);
        else puts("No Answer");
    }
    return 0;
}

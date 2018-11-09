#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
struct Edge{
	int to,len;
};
struct node{
	int num,dis;
	bool operator<(const node& a) const{
		return dis>a.dis;
	}
};
vector<Edge> G[1005];
int vis[1005];
int dis[1005];
int dijkstra(int start,int ed)
{
	memset(vis,0,sizeof(vis));
	memset(dis,0x3f,sizeof(dis));
	node st={start,0};
	dis[start]=0;
	priority_queue<node> q;
	q.push(st);
	while(!q.empty())
	{
		node u=q.top();q.pop();
		if(vis[u.num]) continue;
		vis[u.num]=1;
		for(int i=0;i<G[u.num].size();i++)
		{
			Edge &v=G[u.num][i];
			if(!vis[v.to]&&dis[v.to]>dis[u.num]+v.len)
			{
				dis[v.to]=dis[u.num]+v.len;
				q.push(node {v.to,dis[v.to]});
			}
		}
	}
	return dis[ed];
}
int main()
{
	int m,n;
	while(~scanf("%d%d",&m,&n))
	{
		for(int i=0;i<=n;i++)
			G[i].clear();
		for(int i=0,u,v,len;i<m;i++)
		{
			scanf("%d%d%d",&u,&v,&len);
			G[u].push_back(Edge {v,len});
			G[v].push_back(Edge {u,len});
		}
		printf("%d\n",dijkstra(n,1));
	}
}
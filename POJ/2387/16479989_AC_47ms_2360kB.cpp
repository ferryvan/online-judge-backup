#include<iostream>
#include<cstring>
#include<vector>
#include<queue>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int maxn=1e5+7;
struct Edge{
	int to,len;
};

vector<Edge> G[maxn];
int dis[maxn];
bool inq[maxn];
int spfa(int st,int ed)
{
	memset(inq,0,sizeof(inq));
	memset(dis,0x3f,sizeof(dis));
	queue<int> q;
	q.push(st);
	inq[st]=1;
	dis[st]=0;
	while(!q.empty())
	{
		int u=q.front();q.pop();
		inq[u]=0;
		for(int i=0;i<G[u].size();i++)
		{
			Edge &v=G[u][i];
			if(dis[v.to]>dis[u]+v.len)
			{
				dis[v.to]=dis[u]+v.len;
				if(!inq[v.to]){
					q.push(v.to);
					inq[v.to]=1;
				}
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
		printf("%d\n",spfa(n,1));
	}
}
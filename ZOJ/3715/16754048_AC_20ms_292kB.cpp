#include<bits/stdc++.h>
using namespace std;
int f[105],cost[105];
int ticket[105];
bool cmp(const int a,const int b)
{
	return cost[a]<cost[b];
}
int main()
{
	int T;
	scanf("%d",&T);
	while(T--)
	{
		int n;
		scanf("%d",&n);
		memset(ticket,0,sizeof(ticket));
		for(int i=2;i<=n;i++)
		{
			scanf("%d",&f[i]);
			ticket[f[i]]++;
		}
		for(int i=2;i<=n;i++)
			scanf("%d",&cost[i]);
		int ans=0x3f3f3f3f;
		for(int i=ticket[1];i<=n-1;i++)
		{
			vector<int> lead;
			int cur=0;
			lead.clear();
			int need=0;
			bool vis[105];
			vector<int> person;
			memset(vis,0,sizeof(vis));
			for(int j=2;j<=n;j++)
			{
				if(ticket[j]>i-1)
				{
					lead.push_back(j);
					need+=ticket[j]-i+1;
				}
			}
			if(need>i-ticket[1]) continue;
			for(int j=0;j<lead.size();j++)
			{
				int id=lead[j];
				person.clear();
				for(int k=2;k<=n;k++)
				{
					if(f[k]==id)
						person.push_back(k);
				}
				sort(person.begin(),person.end(),cmp);
				for(int k=0;k<ticket[id]-i+1;k++)
				{
					cur+=cost[person[k]];
					vis[person[k]]=1;
				}
			}
			person.clear();
			for(int j=2;j<=n;j++)
			{
				if(!vis[j])
					person.push_back(j);
			}
			sort(person.begin(),person.end(),cmp);
			for(int j=0;j<i-ticket[1]-need;j++)
			{
				cur+=cost[person[j]];
			}
			ans=min(ans,cur);
		}
		printf("%d\n",ans);
	}

}
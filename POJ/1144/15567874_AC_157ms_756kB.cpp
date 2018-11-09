#include<algorithm>
#include<string>
#include<cstring>
#include<iostream>
#include<sstream>
#include<cstdio>
using namespace std;
int G[107][107];
int dfn[107],low[107];
int tot=0;
int n;
bool inst[107],cur[107];
int par[107];
void dfs(int x,int pre)
{
    dfn[x]=low[x]=++tot;
    par[x]=pre;
    inst[x]=true;
    for(int v=1;v<=n;v++)
    {
        if(G[x][v])
        {
            if(!dfn[v])
            {
                dfs(v,x);
                low[x]=min(low[x],low[v]);
            }
            else if(inst[v])
                low[x]=min(dfn[v],low[x]);
        }
    }
}
int tarjin()
{
    memset(cur,0,sizeof(cur));
    tot=0;
    dfs(1,0);
    int cnt=0,ans=0;
    for(int i=1;i<=n;i++)
    {
        int pre=par[i];
        if(pre==1) cnt++;
        else if(low[i]>=dfn[pre])
            cur[pre]=true;
    }
    if(cnt>1)
        cur[1]=true;
    for(int i=1;i<=n;i++)
    {
        if(cur[i])
            ans++;
    }
    return ans;
}
int main()
{
    #ifndef ONLINE_JUDGE
		freopen("data.in","r",stdin);
		freopen("data.out","w",stdout);
	#endif
    while(cin>>n)
    {
        if(n==0) break;
        int a,b;
        memset(G,0,sizeof(G));
        memset(dfn,0,sizeof(dfn));
        memset(inst,0,sizeof(inst));
        for(int i=0;i<=n;i++)
        {
            scanf("%d",&a);
            if(a==0) break;
            else{
                string s;
                getline(cin,s);
                stringstream ss(s);
                while(ss>>b)
                {
                    G[a][b]=1;
                    G[b][a]=1;
                }
            }
        }
        cout<<tarjin()<<endl;
    }
    return 0;
}
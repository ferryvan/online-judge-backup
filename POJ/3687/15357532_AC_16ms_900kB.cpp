#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=200+7;
int G[N][N],deg[N],ans[N];
int n,m;
int toposort()
{
    int cnt=0;
    for(int i=0;i<n;i++)
    {
        for(int j=n;j>=1;j--)
        {
            if(!deg[j])
            {
                ans[j]=n-cnt;
                cnt++;
                for(int k=1;k<=n;k++)
                {
                    if(G[j][k])
                    {
                        deg[k]--;
                    }
                }
                deg[j]--;
                break;
            }
        }
    }
    if(cnt!=n) return 0;
    return 1;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        int a,b;
        memset(G,0,sizeof(G));
        memset(deg,0,sizeof(deg));
        for(int i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            if(G[b][a]) continue;
            G[b][a]=1;
            deg[a]++;
        }
        int flag=toposort();
        if(!flag)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans[1];
        for(int i=2;i<=n;i++)
        {
            cout<<" "<<ans[i];
        }
        cout<<endl;
    }
    return 0;
}
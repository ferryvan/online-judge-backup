#include<bits/stdc++.h>
using namespace std;
int n;
bool isprime[50];
int vis[20];
int pre[20];
void db()
{
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(int i=2;i<50;i++)
    {
        for(int j=2;j<i;j++)
            {
                if(i%j==0)
                {
                    isprime[i]=0;
                    break;
                }
            }
    }
}
void print(int num)
{
    if(num==1)
    {
        printf("1");
        return;
    }
    print(pre[num]);
    printf(" %d",num);

}
void dfs(int pos,int now)
{
    if(pos==n)
    {
        if(isprime[now+1])
            {
                print(now);
                cout<<endl;
            }
        return;
    }
    for(int i=2;i<=n;i++)
    {
        if(isprime[now+i]&&!vis[i])
        {
            pre[i]=now;
            vis[i]=1;
            dfs(pos+1,i);
            vis[i]=0;
        }
    }
}
int main()
{
    db();
    int flag=0;
    int kas=0;
    while(scanf("%d",&n)==1)
    {
        if(flag) cout<<endl;
        memset(vis,0,sizeof(vis));
        printf("Case %d:\n",++kas);
        vis[1]=1;
        dfs(1,1);
        flag=1;
    }
}

#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=507;
bool isprime[maxn];
int prime[maxn];
int pre[maxn][maxn];
void db()
{
    int tot=0;
    memset(pre,0,sizeof(pre));
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]) prime[++tot]=i;
        for(int j=i;j<maxn;j+=i)
        {
            if(j!=i) isprime[j]=false;
            int temp=j;
            while(temp%i==0)
            {
                pre[j][i]++;
                temp/=i;
            }
        }
    }
    for(int i=1;i<maxn;i++)
    {
        for(int j=1;j<=i;j++)
        {
            pre[i][j]+=pre[i-1][j];
        }
    }
}
long long calc(int n,int k)
{
    long long ret=1;
    for(int i=1;i<=n;i++)
    {
        if(!isprime[i])
            continue;
        long long temp=pre[n][i]-pre[n-k][i]-pre[k][i];
        //cout<<temp<<endl;
        ret*=temp+1;
    }
    return ret;
}
int main()
{
    db();
    int n,k;
    while(~scanf("%d%d",&n,&k))
    {
        long long ans=calc(n,k);
        printf("%lld\n",ans);
    }
    return 0;
}
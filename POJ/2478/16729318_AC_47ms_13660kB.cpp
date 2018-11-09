#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+7;
int euler[maxn];
bool isprime[maxn];
int prime[maxn];
long long ans[maxn];
void db()
{
    euler[1]=1;
    int tot=0;
    memset(isprime,1,sizeof(isprime));
    for(int i=2;i<maxn;i++)
    {
        if(isprime[i]) prime[++tot]=i,euler[i]=i-1;
        for(int j=1;prime[j]*i<maxn;j++)
        {
            isprime[prime[j]*i]=false;
            if(i%prime[j]==0){
                euler[prime[j]*i]=prime[j]*euler[i];
                break;
            }
            euler[prime[j]*i]=euler[i]*(prime[j]-1);
        }
    }
    ans[2]=1;
    for(int i=3;i<maxn;i++)
        ans[i]=ans[i-1]+euler[i];
}
int main()
{
    db();
    int n;
    while(~scanf("%d",&n)&&n)
    {
        printf("%lld\n",ans[n]);
    }
    return 0;
}
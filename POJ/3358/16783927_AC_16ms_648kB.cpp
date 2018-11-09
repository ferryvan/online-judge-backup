#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
long long phi(long long n)
{
    long long ret=n;
    for(int i=2;i*i<=n;i++)
    {
        if(n%i==0)
        {
            ret=ret/i*(i-1);
            while(n%i==0) n/=i;
        }
    }
    if(n>1)
        ret=ret/n*(n-1);
    return ret;
}
long long qucik_pow(long long n,long long p,int mod)
{
    long long ret=1;
    while(p)
    {
        if(p&1)
            ret=ret*n%mod;
        n=n*n%mod;
        p>>=1;
    }
    return ret;
}
int main()
{
    long long p,q;
    int kas=0;
    while(~scanf("%lld/%lld",&p,&q))
    {
        long long gcd=__gcd(p,q);
        p/=gcd;
        q/=gcd;
        long long cnt=0,ans=0;
        while(q%2==0)
            q/=2,cnt++;
        long long limit=phi(q);
        for(long long i=1;i*i<=limit;i++)
        {
            if(limit%i==0&&qucik_pow(2,i,q)==1)
            {
                ans=i;break;
            }
            if(limit%i==0&&qucik_pow(2,limit/i,q)==1)
                ans=limit/i;
        }
        printf("Case #%d: %lld,%lld\n",++kas,cnt+1,ans);
    }
    return 0;
}
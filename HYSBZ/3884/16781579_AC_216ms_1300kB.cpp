#include<bits/stdc++.h>
using namespace std;
int p;
int phi(int num)
{
    int ret=num;
    for(int i=2;i<=sqrt(num);i++)
     if(num%i==0)
      {
        ret=ret/i*(i-1);
        while(num%i==0)
          num/=i;
     }
    if(num>1)
          ret=ret/num*(num-1);
    return ret;
}
long long quickmod(long long in,long long t,long long mod)
{
    long long ret=1;
    long long base=in;
    do{
        if(t&1)
            ret=ret*base;
        base=base*base;
        if(ret>mod) ret=ret%mod+mod;
        if(base>mod) base=base%mod+mod;
    }while(t>>=1);
    return ret;
}
long long dfs(long long t)
{
    if(t==1) return 1;
    return quickmod(2LL,dfs(phi(t)),t);
}
int main()
{
    int T;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d",&p);
        long long ans=dfs(p)%p;
        cout<<ans<<endl;
    }
}
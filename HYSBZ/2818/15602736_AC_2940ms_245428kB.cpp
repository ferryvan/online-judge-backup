#include<bits/stdc++.h>
using namespace std;
const int N=1e7+7;
long long phi[N],sumphi[N],prime[N];
bool isprime[N];
int cntp=0;
int n;
void db()
{
    cntp=0;
    phi[1]=1;
    memset(prime,0,sizeof(prime));
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(int i=2;i<=n;i++)
    {
        if(isprime[i])
        {
            prime[cntp++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<cntp&&i*prime[j]<=n;j++)
        {
            isprime[i*prime[j]]=0;
            if(i%prime[j]==0)
            {
                phi[i*prime[j]]=phi[i]*prime[j];
                break;
            }
            else phi[i*prime[j]]=phi[i]*(prime[j]-1);
        }
    }
    sumphi[0]=0;
    for(int i=1;i<=n;i++) sumphi[i]=sumphi[i-1]+phi[i];
}
int main()
{
    while(cin>>n)
    {
        db();
        long long ans=0;
        for(int i=0;i<cntp;i++)
            ans+=sumphi[n/prime[i]];
        cout<<ans*2-cntp<<endl;
    }
    return 0;
}
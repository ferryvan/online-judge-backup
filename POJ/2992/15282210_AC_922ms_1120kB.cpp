#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int prime[450];
bool isprime[450];
int cnt=0;
int e[450][500];
void db()
{
    memset(isprime,1,sizeof(isprime));
    isprime[0]=isprime[1]=0;
    for(int i=2;i<444;i++)
    {
        if(isprime[i])
        {
            prime[cnt++]=i;
            for(int j=i*2;j<444;j+=i)
            {
                isprime[j]=0;
            }
        }
    }
    memset(e,0,sizeof(e));
    for(int i=2;i<438;i++)
    {
        for(int k=1;k<=i;k++)
        {
            int ss=k;
            for(int j=0;j<cnt&&prime[j]<=k;j++)
            {
                while(ss%prime[j]==0)
                {
                    e[i][prime[j]]++;
                    ss/=prime[j];
                }
            }
        }
    }
}
long long cal(int n,int k)
{
    long long ans=1,rec;
    for(int i=1;i<=n;i++)
    {
        rec=e[n][i]-e[k][i]-e[n-k][i];
        if(rec)
            ans*=rec+1;
    }
    return ans;
}
int main()
{
    db();
    int n,k;
    while(cin>>n>>k)
    {
        cout<<cal(n,k)<<endl;
    }
    return 0;
}
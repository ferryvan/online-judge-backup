#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    int n,s,price[10001],demand[10001];
    long long ans=0;
    bool vis[10001]={0};
    scanf("%d%d",&n,&s);
    for(int i=0;i<n;i++)
        scanf("%d%d",&price[i],&demand[i]);
    for(int i=0;i<n;i++)
    {
        if(!vis[i])
        {
            vis[i]=1;
            ans+=demand[i]*price[i];
        for(int j=i+1;j<n;j++)
        {
            if(!vis[j]&&s*(j-i)+price[i]<=price[j])
            {
                vis[j]=1;
                ans+=s*(j-i)*demand[j]+price[i]*demand[j];
            }
        }
        }
    }
    printf("%lld\n",ans);
    return 0;
}

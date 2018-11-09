#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;

int main()
{
    int t;
    cin>>t;
    int a[50007];
    int dpl[50007];
    int dpr[50007];
    while(t--)
    {
        memset(dpr,0,sizeof(dpr));
        memset(dpl,0,sizeof(dpl));
        int n;
        cin>>n;
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        dpl[0]=a[0];
        for(int i=1;i<n;i++)
        {
            dpl[i]=max(dpl[i-1]+a[i],a[i]);
        }
        dpr[n-1]=a[n-1];
        for(int i=n-2;i>=0;i--)
        {
            dpr[i]=max(dpr[i+1]+a[i],a[i]);
        }
        int ans=-INF;
        for(int i=1;i<n;i++)
            dpl[i]=max(dpl[i],dpl[i-1]);
        for(int i=n-2;i>=0;i--)
            dpr[i]=max(dpr[i],dpr[i+1]);
        for(int i=1;i<n;i++)
            ans=max(ans,dpl[i-1]+dpr[i]);
        cout<<ans<<endl;
    }
    return 0;
}
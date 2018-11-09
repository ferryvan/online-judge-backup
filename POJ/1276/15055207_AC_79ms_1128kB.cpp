#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int cash,n;
    int num,d[15000],dd;
    int dp[100007];
    while(cin>>cash>>n)
    {
        int cnt=0;
        memset(dp,0,sizeof(dp));
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&num,&dd);
            for(int k=1;k<=num;k<<=1)
            {
                d[cnt++]=k*dd;
                num-=k;
            }
            if(num>0)
            {
                d[cnt++]=num*dd;
            }
        }
        for(int i=0;i<cnt;i++)
        {
            for(int j=cash;j>=d[i];j--)
            {
               dp[j]=max(dp[j],dp[j-d[i]]+d[i]);
            }
        }
        cout<<dp[cash]<<endl;
    }
    return 0;
}
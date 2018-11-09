#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int INF=0x3f3f3f3f;
int n,v[2007];
int dp[2007][2007];
int main()
{
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
        {
            cin>>v[i];
        }
        memset(dp,0,sizeof(dp));
        dp[0][0]=0;
        for(int i=0;i<=n;i++)
        {
            for(int j=0;j<=n;j++)
            {
                if(i==0&&j==0)
                    continue;
                else if(i==0)
                    dp[i][j]=dp[0][j-1]+v[n-j+1]*(i+j);
                else if(j==0)
                    dp[i][j]=dp[i-1][j]+v[i]*(i+j);
                else dp[i][j]=max(dp[i-1][j]+v[i]*(i+j),dp[i][j-1]+v[n-j+1]*(i+j));
            }
        }
        int ans=-INF;
        for(int i=0;i<=n;i++)
            ans=max(ans,dp[i][n-i]);
        cout<<ans<<endl;
    }
    return 0;
}
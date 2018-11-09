#include<bits/stdc++.h>
using namespace std;
int dp[2101][2101];
int main()
{
    memset(dp,0,sizeof(dp));
    string A,B;
    cin>>A>>B;
    for(int i=3;i<=A.length();i++)
    {
        for(int j=3;j<=B.length();j++)
        {
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            if(A[i-1]==B[j-1]&&A[i-2]==B[j-2]&&A[i-3]==B[j-3])
            {
                int cnt=3;
                for(int k=1;i-3-k>=0&&j-3-k>=0;k++)
                {
                    if(A[i-3-k]==B[j-3-k])
                        cnt++;
                    else break;
                }
                dp[i][j]=max(dp[i][j],max(dp[i-cnt][j-cnt]+cnt,dp[i-3][j-3]+3));
            }
        }
    }
    cout<<dp[A.length()][B.length()]<<endl;
    return 0;
}
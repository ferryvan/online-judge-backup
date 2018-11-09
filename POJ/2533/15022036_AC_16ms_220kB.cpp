#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e6+7;
int main()
{
    int n,a[1007];
    while(cin>>n)
    {
        for(int i=1;i<=n;i++)
            cin>>a[i];
        int dp[1007];
        dp[0]=0;
        dp[1]=a[1];
        int len=1;
        for(int i=2;i<=n;i++)
        {
            if(a[i]>dp[len]) dp[++len]=a[i];
            else {
                int j=upper_bound(dp+1,dp+len+1,a[i])-dp;
                dp[j]=a[i];
            }
        }
        cout<<len<<endl;
    }
    return 0;
}
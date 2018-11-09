#include<cstdio>
#include<cstring>
using namespace std;
int a[40];
int dp[40][40][40];
int dfs(int pos,int zero,int lead,bool limit)
{
    if(pos==-1)
    {
        if(lead%2==0)
        {if(zero>=lead/2) return 1;}
        else{
            if(zero>lead/2) return 1;
        }
        return 0;
    }
    if(!limit&&dp[pos][zero][lead]!=-1) return dp[pos][zero][lead]; 
    int up=limit?a[pos]:1;
    int ret=0;
    for(int i=0;i<=up;i++)
    {
        if(lead) ret+=dfs(pos-1,zero+1-i,lead,limit&&i==up);
        else ret+=dfs(pos-1,zero,i==1?(pos+1):0,limit&&i==up);
    }
    if(!limit) dp[pos][zero][lead]=ret;
    return ret;
}
int solve(int n)
{
    int pos=0;
    do{
        a[pos++]=n&1;
    }while(n>>=1);
    return dfs(pos-1,0,0,1);
}
int main()
{
    int st,ed;
    memset(dp,-1,sizeof(dp));
    while(~scanf("%d%d",&st,&ed))
    {
        printf("%d\n",solve(ed)-solve(st-1));
    }
    return 0;
}
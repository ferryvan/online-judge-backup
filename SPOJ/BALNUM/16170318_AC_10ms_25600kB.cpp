#include<bits/stdc++.h>
using namespace std;
int a[21];
long long dp[21][60000];
long long weigh[21];
bool judge(int state)
{
    int pos=0;
    int now=0;
    do{
        now=state%3;
        if(now!=0&&((pos%2==0&&now==2)||(pos%2!=0&&now==1))) return 0;
        pos++;
    }while(state/=3);
    return 1;
}
long long change(int state,int p)
{
    int now=0;
    int pos=0;
    int save=state;
    do{
        if(pos==p)
        {
            now=save%3;
            break;
        }
        pos++;
    }while(save/=3);
    int next;
    if(now==1) next=2;
    else next=1;
    state-=now*weigh[p];
    state+=next*weigh[p];
    return state;
}
long long dfs(int pos,int state,bool limit)
{
    if(pos==-1)
    {
        if(judge(state))
            return 1;
        else return 0;
    }
    if(!limit&&dp[pos][state]!=-1) return dp[pos][state];
    int up=limit?a[pos]:9;
    long long ret=0;
    for(int i=0;i<=up;i++)
    {
        ret+=dfs(pos-1,state==0&&i==0?0:change(state,i),limit&&i==up);
    }
    if(!limit) dp[pos][state]=ret;
    return ret;
}
long long solve(int n)
{
    int pos=0;
    do{
        a[pos++]=n%10;
    }while(n/=10);
    return dfs(pos-1,0,1);
}
int main()
{
    weigh[0]=1;
    for(int i=1;i<21;i++)
        weigh[i]=weigh[i-1]*3;
    int T;
    scanf("%d",&T);
    memset(dp,-1,sizeof(dp));
    while(T--)
    {
        long long l,r;
        scanf("%lld%lld",&l,&r);
        long long ans=solve(r)-solve(l-1);
        printf("%lld\n",ans);
    }
    return 0;
}
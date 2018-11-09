#include<cstdio>
#include<algorithm>
using namespace std;
const int N=1e5+7;
const int INF=0x3f3f3f3f;
int cost[N];
int n,m;
bool judge(int mid)
{
    int sum=0,group=1;
    for(int i=0;i<n;i++)
    {
        if(sum+cost[i]<=mid)
            sum+=cost[i];
        else{
            sum=cost[i];
            group++;
        }
    }
    if(group>m)
        return false;
    else return true;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        int high=0,low=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&cost[i]);
            high+=cost[i];
            low=max(low,cost[i]);
        }
        int mid=(low+high)>>1;
        while(low<high)
        {
            if(judge(mid)) high=mid-1;
            else low=mid+1;
            mid=(low+high)>>1;
        }
        printf("%d\n",mid);
    }
    return 0;
}
#include<cstdio>
#include<algorithm>
#include<cmath>
int n,k;
double L[10005];
bool C(double x)
{
    int num=0;
    for(int i=0;i<n;i++)
        num+=(int)(L[i]/x);
    return num>=k;
}
void solve()
{
    double lb=0,ub=1000000000;
    for(int i=0;i<100;i++)
    {
        double mid=(lb+ub)/2;
        if(C(mid)) lb=mid;
        else ub=mid;
    }
    printf("%.2f\n",floor(ub*100)/100);
}
int main()
{
    while(~scanf("%d%d",&n,&k))
    {
        for(int i=0;i<n;i++)
            scanf("%lf",&L[i]);
        solve();
    }
}
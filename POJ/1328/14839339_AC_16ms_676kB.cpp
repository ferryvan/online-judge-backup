#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
    int x,y;
};
struct line{
    double le,ri;
};
bool cmp(line l1,line l2)
{
    return l1.ri<l2.ri;
}
int n,d,k=0;
Point p[1000];
line l[1000];
bool vis[1000]={0};
int cnt=0;
void init()
{
    cnt=0;
    for(int i=0;i<n;i++)
        vis[i]=0;
}
int main()
{
    while(scanf("%d%d",&n,&d)==2)
    {
        init();
        int flag=1;
        if(n==0&&d==0)
            return 0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&p[i].x,&p[i].y);
            l[i].le=p[i].x-sqrt(d*d-p[i].y*p[i].y);
            l[i].ri=p[i].x+sqrt(d*d-p[i].y*p[i].y);
        }
        printf("Case %d: ",++k);
        sort(l,l+n,cmp);
        for(int i=0;i<n;i++)
        {
            if(p[i].y>d)
            {
                printf("-1\n");
                flag=0;
                break;
            }
            if(!vis[i])
            {
                cnt++;
                for(int j=i;j<n;j++)
                {
                    if(l[j].le<l[i].ri||fabs(l[j].le-l[i].ri)<0.000001)
                        vis[j]=1;
                }
            }
        }
        if(flag)
            printf("%d\n",cnt);
    }
    return 0;

}

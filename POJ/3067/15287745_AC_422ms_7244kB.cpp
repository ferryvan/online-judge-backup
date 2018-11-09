#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
struct segment{
    int le,ri;
}seg[1000*1000+1];
bool cmp(segment a,segment b)
{
    if(a.le==b.le) return a.ri<b.ri;
    return a.le<b.le;
}
int t[1000*1000+1];
void add(int x,int p)
{
    while(x<=1000*1000)
    {
        t[x]+=p;
        x += x & -x;
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=t[x];
        x -= x & -x;
    }
    return ans;
}
int main()
{
    int ti,kas=0;
    cin>>ti;
    while(ti--)
    {
        int n,m,k;
        cin>>n>>m>>k;
        int maxx=0;
        memset(t,0,sizeof(t));
        for(int i=0;i<k;i++)
        {
            scanf("%d%d",&seg[i].le,&seg[i].ri);
            maxx=max(maxx,seg[i].ri);
        }
        sort(seg,seg+k,cmp);
        long long ans=0;
        for(int i=0;i<k;i++)
        {
            add(seg[i].ri,1);
            ans+=sum(maxx)-sum(seg[i].ri);
        }
        printf("Test case %d: ",++kas);
        cout<<ans<<endl;
    }
    return 0;
}
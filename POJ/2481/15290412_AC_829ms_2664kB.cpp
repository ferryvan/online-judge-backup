#include<cstring>
#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;
const int N=1e5+7;
struct segment{
    int le,ri,num;
}seg[N];
bool cmp(segment a,segment b)
{
    if(a.ri==b.ri) return a.le<b.le;
    return a.ri>b.ri;
}
int tree[N];
void add(int x,int p)
{
    while(x<N)
    {
        tree[x]+=p;
        x+=x&-x;
    }
}
int sum(int x)
{
    int ans=0;
    while(x>0)
    {
        ans+=tree[x];
        x-=x&-x;
    }
    return ans;
}
int main()
{
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&seg[i].le,&seg[i].ri);
            seg[i].num=i;
            maxx=max(maxx,seg[i].ri);
        }
        sort(seg,seg+n,cmp);
        int num[N];
        memset(tree,0,sizeof(tree));
        for(int i=0;i<n;i++)
        {
            num[seg[i].num]=sum(seg[i].le+1);
            if(seg[i].le==seg[i-1].le&&seg[i].ri==seg[i-1].ri)
                num[seg[i].num]=num[seg[i-1].num];
            add(seg[i].le+1,1);
        }
        cout<<num[0];
        for(int i=1;i<n;i++)
            cout<<" "<<num[i];
        cout<<endl;
    }
    return 0;
}
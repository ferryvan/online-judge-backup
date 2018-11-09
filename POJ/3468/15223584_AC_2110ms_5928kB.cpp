#include<cstring>
#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e5+7;
long long sum[N*4];
long long lazy[N*4];
void pushup(int rt)
{
    sum[rt]=sum[rt*2]+sum[rt*2+1];
    return;
}
void pushdown(int rt,int len)
{
    lazy[rt*2]+=lazy[rt];
    lazy[rt*2+1]+=lazy[rt];
    sum[rt*2]+=lazy[rt]*(len-len/2);
    sum[rt*2+1]+=lazy[rt]*(len/2);
    lazy[rt]=0;
}
void build(int l,int r,int rt)
{
    if(l==r)
    {
        scanf("%lld",&sum[rt]);
        return ;
    }
    int mid=(l+r)>>1;
    build(l,mid,rt*2);
    build(mid+1,r,rt*2+1);
    pushup(rt);
}
void update(int l,int r,int L,int R,long long val,int rt)
{
    if(l<=L&&r>=R)
    {
        sum[rt]+=val*(R-L+1);
        lazy[rt]+=val;
        return;
    }
    pushdown(rt,R-L+1);
    int mid=(L+R)/2;
    if(l<=mid)
        update(l,r,L,mid,val,rt*2);
    if(r>mid)
        update(l,r,mid+1,R,val,rt*2+1);
    pushup(rt);
}
long long query(int l,int r,int L,int R,int rt)
{
    if(l<=L&&r>=R)
    {
        return sum[rt];
    }
    pushdown(rt,R-L+1);
    long long rec=0;
    int mid=(L+R)/2;
    if(l<=mid)
        rec+=query(l,r,L,mid,rt*2);
    if(r>mid)
        rec+=query(l,r,mid+1,R,rt*2+1);
    return rec;
}
int main()
{
    int n,q;
    cin>>n>>q;
    build(1,n,1);
    char op[10];
    memset(lazy,0,sizeof(lazy));
    for(int i=0;i<q;i++)
    {
        scanf("%s",op);
        if(op[0]=='C')
        {
            int l,r;
            long long val;
            scanf("%d%d%lld",&l,&r,&val);
            update(l,r,1,n,val,1);
        }
        else{
            int l,r;
            scanf("%d%d",&l,&r);
            long long ans;
            ans=query(l,r,1,n,1);
            cout<<ans<<endl;
        }
    }
    return 0;
}
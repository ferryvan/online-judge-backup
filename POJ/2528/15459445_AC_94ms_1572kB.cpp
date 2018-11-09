#include<vector>
#include<iostream>
#include<cstdio>
#include<map>
#include<cstring>
#include<algorithm>
using namespace std;
vector<int> all;
int st[10007],ed[10007];
int sum[150007];
bool vis[10007];
int getid(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
void pushup(int rt)
{
    sum[rt]=0;
}
void pushdown(int rt)
{
    if(sum[rt])
    {
        sum[rt*2]=sum[rt];
        sum[rt*2+1]=sum[rt];
    }
}
void update(int l,int r,int val,int L,int R,int rt)
{
    //printf("l:%d r:%d L:%d R:%d rt:%d\n",l,r,L,R,rt);
    if(l>R||r<L) return;
    if(l<=L&&r>=R)
    {
        sum[rt]=val;
        pushdown(rt);
        return ;
    }
    pushdown(rt);
    int mid=(L+R)>>1;
    if(l<=mid)
        update(l,r,val,L,mid,rt*2);
    if(r>mid)
        update(l,r,val,mid+1,R,rt*2+1);
    //printf("l:%d r:%d L:%d R:%d rt:%d\n",l,r,L,R,rt);
    pushup(rt);
}
int query(int L,int R,int rt)
{
    if(sum[rt]||L==R)
    {
        if(!vis[sum[rt]])
        {
            vis[sum[rt]]=true;
            return 1;
        }
        else return 0;
    }
    int rec=0;
    int mid=(L+R)>>1;
    rec+=query(L,mid,rt*2);
    rec+=query(mid+1,R,rt*2+1);
    return rec;
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("2528.in","r",stdin);
    freopen("lzy.out","w",stdout);
    #endif
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n;
        scanf("%d",&n);
        int maxx=0;
        memset(sum,0,sizeof(sum));
        memset(vis,0,sizeof(vis));
        //all.erase(all.begin(),all.end());
        all.clear();
        for(int i=1;i<=n;i++)
        {
            scanf("%d%d",&st[i],&ed[i]);
            all.push_back(st[i]);
            all.push_back(ed[i]);
            maxx=max(maxx,ed[i]);
        }
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        for(int i=1;i<=n;i++)
        {
            //printf("i=%d st=%d ed=%d getidst=%d getided=%d getidmaxnn=%d\n",i,st[i],ed[i],getid(st[i]),getid(ed[i]),getid(maxx));
            update(getid(st[i]),getid(ed[i]),i,1,getid(maxx),1);
        }
        printf("%d\n",query(1,getid(maxx),1));
    }
    return 0;
}
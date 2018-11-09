#include<cstring>
#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
const int N=2e4+7;
struct node{
    int vo,pos;
}cow[N];
bool cmp(node a,node b)
{
    if(a.vo==b.vo)  return a.pos<b.pos;
    return a.vo<b.vo;
}
int n;
int tree[N];
int tt[N];
void add(int x,int p)
{
    for(int i=x;i<=N;i+=i&-i)
        tree[i]+=p;
}
void addtt(int x,int p)
{
    for(int i=x;i<=N;i+=i&-i)
        tt[i]+=p;
}
long long sum(int x)
{
    long long ans=0;
    for(int i=x;i>0;i-=i&-i)
        ans+=tree[i];
    return ans;
}
long long sumtt(int x)
{
    long long ans=0;
    for(int i=x;i>0;i-=i&-i)
        ans+=tt[i];
    return ans;
}
int main()
{
    while(cin>>n)
    {
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&cow[i].vo,&cow[i].pos);
        }
        sort(cow,cow+n,cmp);
        long long ans=0;
        memset(tree,0,sizeof(tree));
        memset(tt,0,sizeof(tt));
        for(int i=0;i<n;i++)
        {
            long long pre=sumtt(cow[i].pos)*cow[i].pos-sum(cow[i].pos);
            long long next=(sum(N-2)-sum(cow[i].pos))-cow[i].pos*(sumtt(N-2)-sumtt(cow[i].pos));
            ans+=(next+pre)*cow[i].vo;
            add(cow[i].pos,cow[i].pos);
            addtt(cow[i].pos,1);
        }
        cout<<ans<<endl;
    }
    return 0;
}
#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
const int INF=0x3f3f3f3f;
const int N=1e2+5;
struct node{
    int from,to,weight;
    bool operator < (const node &a)const{
        return weight<a.weight;
    }
}edge[N*N];
int n,m;
int far[N*N];
void init()
{
    for(int i=0;i<=n;i++)
        far[i]=i;
}
int Find(int x)
{
    if(far[x]==x) return x;
    else return far[x]=Find(far[x]);
}
void Union(int x,int y)
{
    x=Find(x),y=Find(y);
    if(x!=y) far[y]=x;
}
int kruskal(int st)
{
    sort(edge,edge+m);
    init();
    int slim=0,cnt=0,first=edge[st].weight;
    for(int i=st;i<m;i++)
    {
        if(Find(edge[i].from)!=Find(edge[i].to))
        {
            Union(edge[i].from,edge[i].to);
            cnt++;
        }
        if(cnt==n-1) 
        {
            slim=edge[i].weight-first;
            break;
        }
    }
    if(cnt<n-1) return INF;
    else return slim;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0) break;
        int a,b,w;
        for(int i=0;i<m;i++)
        {
            scanf("%d%d%d",&a,&b,&w);
            edge[i].from=a;
            edge[i].to=b;
            edge[i].weight=w;
        }
        int ans=INF;
        for(int i=0;i<=m-n+1;i++)
        {
            ans=min(kruskal(i),ans);
            if(i==0&&ans==INF)
                break;
        }
        if(ans==INF)
        {
            cout<<-1<<endl;
            continue;
        }
        cout<<ans<<endl;
    }

}
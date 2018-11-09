#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
struct node
{
    int start,ending;
};
bool cmp(node a,node b)
{
    return a.start<b.start;
}
int main()
{
    int n,t,e=0,maxend;
    node shift[25001];
    scanf("%d%d",&n,&t);
    int cnt=0;
    for(int i=0;i<n;i++)
        scanf("%d%d",&shift[i].start,&shift[i].ending);
    sort(shift,shift+n,cmp);
    maxend=shift[0].ending;
    int i=0;
    while(e!=t)
    {
        if(shift[i].start>e+1||i==n)
        {
            printf("-1\n");
            return 0;
        }
        while(shift[i].start<=e+1&&i<n)
        {
            maxend=max(shift[i].ending,maxend);
            i++;
        }
        e=maxend;
        cnt++;
    }
    printf("%d\n",cnt);
    return 0;
}

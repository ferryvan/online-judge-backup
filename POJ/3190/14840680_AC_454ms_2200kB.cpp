#include<cstdio>
#include<iostream>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
struct duration{
    int start,ending,num,sn;
};
bool cmp(duration a,duration b)
{
    return a.start<b.start;
}
bool cmpn(duration a,duration b)
{
    return a.num<b.num;
}
struct cmps
{
    bool operator() (const pair<int ,int> a,pair<int ,int> b)
    {
        return a.first>b.first;
    }
};
int  main()
{
    int n,ans=0,j;
    pair<int ,int> stall[50000];
    duration d[50000];
    scanf("%d",&n);
    priority_queue<pair<int ,int>,vector<pair<int ,int> >,cmps> qqq;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&d[i].start,&d[i].ending);
        d[i].num=i;
        stall[i].first=0;
        stall[i].second=i;
    }
    sort(d,d+n,cmp);
    stall[0].first=d[0].ending;
    d[0].sn=0;
    qqq.push(stall[0]);
    pair<int ,int> temp;
    for(int i=1;i<n;i++)
    {
        temp=qqq.top();
        //cout<<temp.first<<endl;
        if(temp.first>=d[i].start)
        {
            stall[++ans].first=d[i].ending;
            qqq.push(stall[ans]);
            d[i].sn=ans;
        }
        else
        {
            qqq.pop();
            temp.first=d[i].ending;
            d[i].sn=temp.second;
            qqq.push(temp);
        }
    }
    sort(d,d+n,cmpn);
    printf("%d\n",ans+1);
    for(int i=0;i<n;i++)
        printf("%d\n",d[i].sn+1);

    return 0;
}

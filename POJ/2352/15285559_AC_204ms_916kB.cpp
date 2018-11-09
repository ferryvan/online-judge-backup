#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=32005;
int t[32005];
int level[15005];
int n;
void add(int x,int p)
{
    while(x<N)
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
    while(cin>>n)
    {
        memset(t,0,sizeof(t));
        int x,y;
        memset(level,0,sizeof(level));
        for(int i=0;i<n;i++)
        {   
            scanf("%d%d",&x,&y);
            x++;
            level[sum(x)]++;
            add(x,1);
        }
        for(int i=0;i<n;i++)
            cout<<level[i]<<endl;
    }
    return 0;

}
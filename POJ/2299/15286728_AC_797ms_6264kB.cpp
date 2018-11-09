#include<cstring>
#include<vector>
#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
const int N=5e5+7;
int t[N];
int a[N];
vector<int> all;
int getid(int x)
{
    return lower_bound(all.begin(),all.end(),x)-all.begin()+1;
}
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
    int n;
    while(cin>>n)
    {
        if(n==0) break;
        all.erase(all.begin(),all.end());
        int maxx=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&a[i]);
            all.push_back(a[i]);
            maxx=max(maxx,a[i]);
        }
        sort(all.begin(),all.end());
        all.erase(unique(all.begin(),all.end()),all.end());
        long long ans=0;
        memset(t,0,sizeof(t));
        for(int i=0;i<n;i++)
        {
            add(getid(a[i]),1);
            ans+=sum(getid(maxx))-sum(getid(a[i]));
        }
        cout<<ans<<endl;
    }
    return 0;
}
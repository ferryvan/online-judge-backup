#include<queue>
#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
    int m,n;
    int a[30005],b[30006];
    while(cin>>m>>n)
    {
        for(int i=0;i<m;i++)
            scanf("%d",&a[i]);
        priority_queue<int,vector<int>,greater<int> > small;
        priority_queue<int> big;
        for(int i=1;i<=n;i++)
            scanf("%d",&b[i]);
        int cnt=1;
        for(int i=0;i<m;i++)
        {
            small.push(a[i]);
            while(!big.empty()&&big.top()>small.top())
            {
                int t=small.top();
                small.pop();
                small.push(big.top());
                big.push(t);
                big.pop();
            }
            while(i+1==b[cnt])
            {
                int t=small.top();
                small.pop();
                big.push(t);
                cout<<big.top()<<endl;
                cnt++;
            }
        }
    }
    return 0;
}

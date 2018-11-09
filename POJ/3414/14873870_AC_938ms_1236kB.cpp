#include<cstdio>
#include<iostream>
#include<queue>
#include<cstring>
#include<string>
using namespace std;
typedef long long ll;
typedef pair<int,int> PII;
const int INF=0x3f3f3f3f;
const int N=32;
struct node {
    int aa,bb;
    string op;
};
node pre[102][102];
int vis[102][102];

void print(int a, int b)
{
    if(a==0&&b==0)
        return ;
    print(pre[a][b].aa,pre[a][b].bb);
    cout<<pre[a][b].op<<endl;
}

int main()
{
    int a,b,c;
    memset(vis,0x3f,sizeof(vis));
    scanf("%d%d%d",&a,&b,&c);
    queue<PII> qqq;
    while(!qqq.empty())
        qqq.pop();
    qqq.push(make_pair(0,0));
    vis[0][0]=0;
    int flag=1;
    string opt;
    while(!qqq.empty())
    {
        PII t=qqq.front(),tt;
        qqq.pop();
        int ans=vis[t.first][t.second];
        if(t.first==c||t.second==c)
        {
            cout<<ans<<endl;
            print(t.first,t.second);
            flag=0;
            break;
        }
        for(int i=1;i<=6;i++)
        {
            tt.first=t.first;
            tt.second=t.second;
            switch(i){
            case 1: tt.first=a;opt="FILL(1)";break;
            case 2: tt.second=b;opt="FILL(2)";break;
            case 3: tt.first=0;opt="DROP(1)"; break;
            case 4: tt.second=0;opt="DROP(2)";break;
            case 5: tt.second=min(t.first+t.second,b);tt.first=(t.first+t.second>b)?(t.first+t.second-b):0;opt="POUR(1,2)";break;
            case 6: tt.first=min(t.first+t.second,a);tt.second=(t.first+t.second>a)?(t.first+t.second-a):0;opt="POUR(2,1)";break;
            }
            if(vis[tt.first][tt.second]==INF)
            {
                qqq.push(tt);
                pre[tt.first][tt.second].op=opt;
                pre[tt.first][tt.second].aa=t.first;
                pre[tt.first][tt.second].bb=t.second;
                vis[tt.first][tt.second]=vis[t.first][t.second]+1;
            }
        }
    }
    if(flag)
        cout<<"impossible"<<endl;
    return 0;
}

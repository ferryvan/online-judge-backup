#include<iostream>
#include<cstdio>
#include<algorithm>
#include<string>
#include<cstring>
#include<queue>
using namespace std;
typedef pair<int,int> PII;
#define X first
#define Y second
PII stt,edd;
string st,ed;
int vis[9][9];
const int INF=0x3f3f3f3f;
int dx[]={1,2,-1,-2,1,2,-1,-2},dy[]={-2,-1,2,1,2,1,-2,-1};
void bfs()
{
    queue<PII> qq;
    while(!qq.empty())
        qq.pop();
    qq.push(stt);
    PII temp;
    vis[stt.X][stt.Y]=0;
    while(!qq.empty())
    {
        //cout<<temp.X<<temp.Y<<endl;
        temp=qq.front();
        qq.pop();
        if(temp.X==edd.X&&temp.Y==edd.Y)
        {
            cout<<"To get from "<<st<<" to "<<ed<<" takes "<<vis[temp.X][temp.Y]<<" knight moves."<<endl;
            return ;
        }
        for(int i=0;i<8;i++)
        {
            PII tt=temp;
            tt.X+=dx[i];tt.Y+=dy[i];
            if(tt.X<8&&tt.X>=0&&tt.Y<8&&tt.Y>=0&&vis[tt.X][tt.Y]==-1)
            {
                qq.push(tt);
                vis[tt.X][tt.Y]=vis[temp.X][temp.Y]+1;
            }
        }
    }
}
int main()
{
    while(cin>>st>>ed)
    {
        memset(vis,-1,sizeof(vis));
        stt.X=st[0]-'a';
        stt.Y=st[1]-'0'-1;
        edd.X=ed[0]-'a';
        edd.Y=ed[1]-'0'-1;
        bfs();
    }
    return 0;
}

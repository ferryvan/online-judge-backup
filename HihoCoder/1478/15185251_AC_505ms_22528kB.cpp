#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;

int n,m;
char maze[805][805];
int vis[805][805];
int dx[]={0,1,0,-1},dy[]={1,0,-1,0};
void bfs()
{
    memset(vis,-1,sizeof(vis));
    queue<pair<int,int> > qq;
    while(!qq.empty()) qq.pop();
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<m;j++)
        {
            if(maze[i][j]=='0')
            {
                qq.push(make_pair(i,j));
                vis[i][j]=0;
            }
        }
    }
    while(!qq.empty())
    {
        pair<int,int> temp=qq.front();
        qq.pop();
        for(int i=0;i<4;i++)
        {
            pair<int,int> tt=temp;
            tt.first+=dx[i];tt.second+=dy[i];
            if(tt.first<n&&tt.second<m&&tt.first>=0&&tt.second>=0&&vis[tt.first][tt.second]==-1)
            {
                qq.push(tt);
                vis[tt.first][tt.second]=vis[temp.first][temp.second]+1;
            }
        }
    }
}
int main()
{
    while(cin>>n>>m)
    {
        getchar();
        for(int i=0;i<n;i++)
        {
            scanf("%s",maze[i]);
        }
        bfs();
        for(int i=0;i<n;i++)
        {
            cout<<vis[i][0];
            for(int j=1;j<m;j++)
                cout<<" "<<vis[i][j];
            cout<<endl;
        }
    }
    return 0;
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tree[1005][1005];
int n;
int query(int x,int y)
{
    int ret = 0;
    for(int i = x;i > 0;i -= i&-i)
        for(int j = y;j > 0;j -= j&-j)
            ret += tree[i][j];
    return ret;
}
void add(int x,int y,int val)
{
    for(int i = x;i <= n;i += i&-i)
        for(int j = y;j <= n;j += j&-j)
            tree[i][j] += val;
}
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int q;
        cin>>n>>q;
        char op[10];
        int x1,x2,y1,y2;
        memset(tree,0,sizeof(tree));
        for(int i=0;i<q;i++)
        {
            scanf("%s",op);
            if(op[0]=='C')
            {
                scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
                add(x1,y1,1);
                add(x2+1,y2+1,1);
                add(x1,y2+1,1);
                add(x2+1,y1,1);
            }
            else{
                scanf("%d%d",&x1,&y1);
                cout<<(query(x1,y1)%2)<<endl;
            }
        }
        if(t)
            cout<<endl;
    }
}
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int tree[1030][1030];
int n;
int sum(int x,int y)
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
    int ins,x1,y1,x2,y2,tt;
    while(cin>>ins)
    {
        if(ins==0)
        {
            cin>>n;
            memset(tree,0,sizeof(tree));
        }
        else if(ins==1)
        {
            scanf("%d%d%d",&x1,&y1,&tt);
            add(x1+1,y1+1,tt);
        }
        else if(ins==2)
        {
            scanf("%d%d%d%d",&x1,&y1,&x2,&y2);
            cout<<sum(x2+1,y2+1)-sum(x2+1,y1)-sum(x1,y2+1)+sum(x1,y1)<<endl;
        }
        else if(ins==3)
            break;
    }
    return 0;
}
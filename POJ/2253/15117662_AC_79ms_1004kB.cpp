#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
const int INF=0x3f3f3f3f;
struct point{
    int x,y;
    double operator - (const point &a)const{
        return fabs(sqrt((x-a.x)*(x-a.x)+(y-a.y)*(y-a.y)));
    }
}stone[205];
int main()
{
    int n,kas=0;
    double G[205][205];
    while(cin>>n)
    {
        if(n==0) break;
        for(int i=0;i<n;i++)
        {
            scanf("%d%d",&stone[i].x,&stone[i].y);
        }
        memset(G,0,sizeof(G));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(i==j) continue;
                G[i][j]=G[j][i]=stone[i]-stone[j];
            }
        }
        for(int k=0;k<n;k++)
            for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                    if(G[i][j]>max(G[i][k],G[k][j]))
                        G[i][j]=max(G[i][k],G[k][j]);
        printf("Scenario #%d\nFrog Distance = %.3f\n",++kas,G[0][1]);
        cout<<endl;
    }
    return 0;
}
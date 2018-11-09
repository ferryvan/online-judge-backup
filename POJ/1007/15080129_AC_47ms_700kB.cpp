#include<iostream>
#include<cstdio>
#include<string>
#include<algorithm>
using namespace std;
struct state{
    int invers,num;
};
bool cmp(state x,state y)
{
    if(x.invers==y.invers)  return x.num<y.num;
    return x.invers<y.invers;
}
int main()
{
    int n,m;
    string s[107];
    while(cin>>n>>m)
    {
        state inn[107];
        for(int i=0;i<m;i++)
            cin>>s[i];
        for(int i=0;i<m;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                for(int k=j+1;k<n;k++)
                {
                    if(s[i][j]>s[i][k])
                        cnt++;
                }
            }
            inn[i].invers=cnt;
            inn[i].num=i;
        }
        sort(inn,inn+m,cmp);
        for(int i=0;i<m;i++)
        {
            cout<<s[inn[i].num]<<endl;
        }
    }
    return 0;
}
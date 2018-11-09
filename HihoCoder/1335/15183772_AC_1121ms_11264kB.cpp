#include<bits/stdc++.h>
using namespace std;
const int N=1e4+7;
int far[N];
void init()
{
    for(int i=0;i<N;i++)
        far[i]=i;
}
int Find(int x)
{
    if(x==far[x]) return x;
    else return far[x]=Find(far[x]);
}
void Union(int x,int y)
{
    x=Find(x);y=Find(y);
    if(x!=y)
    {
        if(x>y) far[x]=y;
        else far[y]=x;
    }
}
int main()
{
    int n;
    while(cin>>n)
    {
        int m;
        string name,address[12];
        map<string,string> mail;
        map<string,int> number;
        map<int,string> nnn;
        init();
        for(int i=0;i<n;i++)
        {
            cin>>name>>m;
            number[name]=i;
            nnn[i]=name;
            for(int j=0;j<m;j++)
                cin>>address[j];
            for(int j=0;j<m;j++)
            {
                if(mail.count(address[j]))
                {
                    Union(number[mail[address[j]]],number[name]);
                }
                else mail[address[j]]=name;
            }
        }
        for(int i=0;i<n;i++)
        {
            int flag=0;
            for(int j=0;j<n;j++)
            {
                if(Find(j)==j&&j==i) 
                {
                    cout<<nnn[j];
                    flag=1;
                }
                else if(Find(j)==i) cout<<" "<<nnn[j];
            }
            if(flag)
                cout<<endl;
        }
    }
    return 0;
}
#include<bits/stdc++.h>
using namespace std;
string pre,in;
int pp[30],ii[30];
int lch[30],rch[30];
int build(int L1,int R1,int L2,int R2)
{
    if(L1>R1) return 0;
    int root=pp[L2];
    int p=L1;
    while(ii[p]!=root) p++;
    int cnt=p-L1;
    lch[root]=build(L1,p-1,L2+1,L2+cnt);
    rch[root]=build(p+1,R1,L2+cnt+1,R2);
    return root;
}
void print(int root)
{
    if(root==0) return;
    print(lch[root]);
    print(rch[root]);
    printf("%c",root+'A'-1);
}
int main()
{
    while(cin>>pre>>in)
    {
        for(int i=0;i<pre.length();i++)
        {
            pp[i]=pre[i]-'A'+1;
            ii[i]=in[i]-'A'+1;    
        }
        build(0,in.length()-1,0,pre.length()-1);
        print(pp[0]);
        cout<<endl;
    }
    return 0;
}
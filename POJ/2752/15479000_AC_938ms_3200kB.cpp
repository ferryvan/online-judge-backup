#include<string>
#include<iostream>
using namespace std;
int F[400005];
int ans[400005];
int main()
{
    string s;
    F[0]=-1;
    while(cin>>s)
    {
        int cnt=0;
        for(int i=1;i<s.length();i++)
        {
            int j=F[i-1];
            while(s[j+1]!=s[i]&&j>=0)
                j=F[j];
            if(s[j+1]==s[i])
                F[i]=j+1;
            else F[i]=-1;
        }
        int i=s.length()-1;
        while(i!=-1)
        {
            ans[cnt++]=i+1;
            i=F[i];
        }
        cout<<ans[cnt-1];
        for(int j=cnt-2;j>=0;j--)
            cout<<" "<<ans[j];
        cout<<endl;
    }
    return 0;
}
#include<string>
#include<cstdio>
#include<iostream>
using namespace std;
const int N=1e6+7;
int F[N];
int main()
{
    char str[N];
    F[0]=-1;
    while(scanf("%s",str)==1)
    {
        if(str[0]=='.') break;
        string s=str;
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
        int ans=1;
        if(F[s.length()-1]!=-1 && s.length()%(s.length()-F[s.length()-1]-1)==0)
            ans=s.length()/(s.length()-F[s.length()-1]-1);
        printf("%d\n",ans);
    }
    return 0;
}
#include<cstdio>
#include<iostream>
#include<string>
#include<algorithm>
#include<sstream>
using namespace std;
const int INF=0x3f3f3f3f;
int main()
{
    int t;
    string ss;
    cin>>t;
    getchar();
    int a[11];
    while(t--)
    {
        int cnt=0;
        getline(cin,ss);
        stringstream s(ss);
        while(s >> a[cnt])
            cnt++;
        sort(a,a+cnt);
        int ans=INF;
        int temp1,temp2;
        do
        {
            temp1=a[0],temp2=a[1];
            if(temp1==0||temp2==0)
                continue;
            for(int i=2;i<cnt;i+=2)
            {
                temp1=temp1*10+a[i];
                if(i+1<cnt)
                temp2=temp2*10+a[i+1];
            }
            ans=min(ans,abs(temp1-temp2));
        }while(next_permutation(a,a+cnt));
        if(cnt==2&&(a[0]==0||a[1]==0))
            ans=max(a[0],a[1]);
        cout<<ans<<endl;

    }
}

#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while(scanf("%d",&n)==1)
    {
        long long ans=1;
        for(int i=n;i>=1;i--)
            ans*=i;
        cout<<ans<<endl;
    }
    return 0;

}

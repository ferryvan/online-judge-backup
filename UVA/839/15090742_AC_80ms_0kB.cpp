#include<bits/stdc++.h>
using namespace std;
bool solve(int &W)
{
    int w1,d1,w2,d2;
    bool b1=1,b2=2;
    cin>>w1>>d1>>w2>>d2;
    if(!w1) b1=solve(w1);
    if(!w2) b2=solve(w2);
    W=w1+w2;
    return b1&&b2&&(w1*d1==w2*d2);
}
int main()
{
    int T,W;
    cin>>T;
    while(T--)
    {
        if(solve(W)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
        if(T) cout<<endl;
    }
    return 0;
}
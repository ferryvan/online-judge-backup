#include<bits/stdc++.h>
using namespace std;
const int maxn=1e7+5;
typedef long long LL;
int p[maxn],phi[maxn];
bool prime[maxn];
LL eular(LL x)
{
    LL ret=1;
    for(int i=2;i*i<=x;i++){
        if(x%i==0){
            ret*=i-1;
            x/=i;
            while(x%i==0){
                ret*=i;
                x/=i;
            }
        }
    }
    if(x>1) ret*=x-1;
    return ret;
}
LL MOD(LL x,LL y)
{
    return x<y?x:x%y+y;
}
LL power(LL a,LL n,LL mod)
{
    LL ret=1;
    a=MOD(a,mod);
    while(n){
        if(n&1) ret=MOD(ret*a,mod);
        a=MOD(a*a,mod);
        n>>=1;
    }
    return ret;
}
LL dfs(LL mod)
{
    if(mod==1) return MOD(2,mod);
    return power(2LL,dfs(eular(mod)),mod);
}
int main()
{
    int n;
    cin>>n;
    while(n--){
        LL mod;
        cin>>mod;
        cout<<dfs(mod)%mod<<endl;
    }
    return 0;
}

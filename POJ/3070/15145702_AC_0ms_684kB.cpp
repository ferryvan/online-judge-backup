#include<cstring>
#include<iostream>
using namespace std;
const int maxn=2;
const int MOD=10000;
struct mat
{
    long long a[maxn][maxn];
    void init() 
    { 
	    memset(a, 0, sizeof(a));
        for (int i=0;i<maxn;i++)
        {
            for(int j=0;j<maxn;j++)
                if(i==j)
                    a[i][j] = 1;
                else a[i][j]=0;
        }
    }
    void clear()
    {
        memset(a, 0, sizeof(a));
    }
    mat operator *(const mat &b)const {
        mat c; c.clear();
        for (int i = 0; i < maxn; i++)
            for (int j = 0; j < maxn; j++)
                for (int k = 0; k < maxn; k++)
                    c.a[i][j] = (c.a[i][j] + a[i][k] * b.a[k][j]) % MOD;
        return c;
    }
};
mat quick_pow(mat a, long long n)
{
    mat ans;
    ans.init();
    while (n)
    {
        if (n & 1) ans = ans*a;
            a = a*a;
            n >>= 1;
    }
         return ans;
}

int main()
{
    int n;
    while(cin>>n)
    {
        if(n==-1) break;
        mat rec={1,1,1,0};
        if(n==0) 
        {
            cout<<0<<endl;
            continue;
        }
        rec=quick_pow(rec,n);
        cout<<rec.a[0][1]<<endl;
    }
    return 0;
}
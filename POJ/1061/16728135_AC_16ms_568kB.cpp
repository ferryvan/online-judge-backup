#include<iostream>
#include<cstdio>
using namespace std;
void ex_gcd(long long a,long long b,long long &gcd,long long &x,long long &y)
{
    if(b==0)
    {
        x=1,y=0;
        gcd=a;
        return ;
    }
    else{
        //y+=x*(a/b);
        ex_gcd(b,a%b,gcd,y,x);
        y-=x*(a/b);
        return;
    }
}
int main()
{
    long long x,y,m,n,l;
    cin>>x>>y>>m>>n>>l;
    long long gcd,t,k;
    long long a=m-n;
    long long c=y-x;
    if(a<0) a=-a,c=-c;
    ex_gcd(a,l,gcd,t,k);
    if(c%gcd!=0) puts("Impossible");
    else{
        long long temp=l/gcd;
        t=t*c/gcd;
        t%=temp;
        if(t<0) t+=temp;
        cout<<t<<endl;
    }
    //system("pause");
}
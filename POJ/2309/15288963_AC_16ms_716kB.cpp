#include<iostream>
#include<cstdio>
using namespace std;
int lowbits(int x)
{
    return x & -x;
}
int main()
{
    int le,ri;
    int t;
    cin>>t;
    while(t--)
    {
        int x;
        cin>>x;
        le=x;ri=x;
        while(le%2==0)
        {
            le=le-lowbits(le)+lowbits(le)/2;
            ri=ri+lowbits(ri)/2;
        }
        printf("%d %d\n",le,ri);
    }
    return 0;
}
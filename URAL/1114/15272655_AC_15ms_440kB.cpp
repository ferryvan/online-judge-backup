#include<bits/stdc++.h>
using namespace std;
unsigned long long C[50][50];
void init()
{
    C[0][0]=1;
    for(int i=1;i<=49;i++)
        C[i][0]=1;
    for(int i=1;i<=49;i++)
    {
        for(int j=1;j<=i;j++)
            C[i][j]=C[i-1][j-1]+C[i-1][j];
    }
}

int main()
{
    init();
    int n,a,b;
    while(cin>>n>>a>>b)
    {
        cout<<C[n+a][n]*C[n+b][n]<<endl;
    }
    return 0;

}
#include <cmath>
#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

int a[10050];

int main(){
    int n,k,l,r,mid,cnt;
    double cur;
    while (~scanf("%d%d",&n,&k)){
        l=r=0;
        for (int i=0;i<n;++i){
            scanf("%lf",&cur);
            a[i]=(int)(cur*100);
            r+=a[i];
        }
        ++r;
        r=1000000000;
        while (r-l>1){
            mid=(l+r)/2;
            cnt=0;
            for (int i=0;i<n;++i){
                cnt+=(a[i]/mid);
            }
            if (cnt>=k) l=mid;
            else r=mid;
            //cout<<l<<' '<<r<<' '<<mid<<' '<<cnt<<endl;
        }
        cur=l/100.0;
        printf("%.2f\n",cur);
    }
    return 0;
}

#include<cstdio>
#include<queue>
#include<functional>
using namespace std;

int main()
{
    int gr,le,n;
    int temp;
    while(~scanf("%d%d%d",&gr,&le,&n))
    {
        if(gr==0&&le==0&&n==0)
            break;
        priority_queue<int> least;
        priority_queue<int,vector<int>,greater<int> > great;
        double aver=0;
        for(int i=0;i<n;i++)
        {
            scanf("%d",&temp);
            least.push(temp);
            great.push(temp);
            if(least.size()>le)
                least.pop();
            if(great.size()>gr)
                great.pop();
            aver+=double(temp)/(n-gr-le);
        }
        while(!least.empty())
        {
            temp=least.top();
            least.pop();
            aver-=double(temp)/(n-gr-le);
        }
        while(!great.empty())
        {
            temp=great.top();
            great.pop();
            aver-=double(temp)/(n-gr-le);
        }
        printf("%.6f\n",aver);
    }
    return 0;
}
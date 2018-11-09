#include <iostream>
#include <cstdio>
#include <cstring>
#include <cmath>
#include <algorithm>
using namespace std;
 
const int N = 30010;
struct node
{
    int l, r, id;
}q[N*10];
int n, m, unit, tmp;
int res[N*10], num[N];
int arr[N], brr[N];
 
void add(int i)
{
    if(! num[i]) tmp++;
    num[i]++;
}
void del(int i)
{
    num[i]--;
    if(! num[i]) tmp--;
}
void solve()
{
    unit = (int)sqrt(n);
    sort(q + 1, q + 1 + m, [](node a, node b){return a.l/unit != b.l/unit ? a.l/unit < b.l/unit : a.r < b.r;});
    int l = 1, r = 0;
    tmp = 0;
    for(int i = 1; i <= m; i++)
    {
        while(r < q[i].r) add(arr[++r]);
        while(r > q[i].r) del(arr[r--]);
        while(l < q[i].l) del(arr[l++]);
        while(l > q[i].l) add(arr[--l]);
        res[q[i].id] = tmp;
    }
    for(int i = 1; i <= m; i++) printf("%d\n", res[i]);
}
int main()
{
    scanf("%d", &n);
    for(int i = 1; i <= n; i++) scanf("%d", &arr[i]), brr[i] = arr[i];
    sort(brr + 1, brr + 1 + n);
    for(int i = 1; i <= n; i++) arr[i] = lower_bound(brr + 1, brr + 1 + n, arr[i]) - brr;
    scanf("%d", &m);
    for(int i = 1; i <= m; i++) scanf("%d%d", &q[i].l, &q[i].r), q[i].id = i;
    solve();
    return 0;
}

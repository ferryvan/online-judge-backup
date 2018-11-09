#include <iostream>
#include <vector>
#include <cstdio>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#include <queue>
#include <set>
#include <cmath>
#include <sstream>
#include <stack>
#include <fstream>
#include <ctime>
#pragma warning(disable:4996);
#define mem(sx,sy) memset(sx,sy,sizeof(sx))
#define llINF 0x3f3f3f3f3f3f3f3f
//#define INF 0x3f3f3f3f
//#define MAXN 1000005
#define pa pair<int, int>
typedef long long ll;
using namespace std;
const double PI = acos(-1.0);
struct Point {
	int x, y;
	Point(int _x = 0, int _y = 0) {
		x = _x; y = _y;
	}
	Point operator -(const Point &b)const {
		return Point(x - b.x, y - b.y);
	}
	int operator ^(const Point &b)const {
		return x * b.y - y * b.x;
	}
	int operator *(const Point &b)const {
		return x * b.x + y * b.y;
	}
	void input() {
		scanf("%d%d", &x, &y);
	}
};

const int maxn = 50010;
int n;
vector<Point> vec;

int dist2(Point a, Point b) {
	return (a - b)*(a - b);
}

int cross(Point p0, Point p1, Point p2) {//P0P1 x P0P2
	return (p1.x - p0.x)*(p2.y - p0.y) - (p1.y - p0.y)*(p2.x - p0.x);
}

bool _cmp(Point p1, Point p2) {
	int tmp = cross(vec[0], p1, p2);
	if (tmp == 0)
		return dist2(p1, vec[0]) <= dist2(p2, vec[0]);
	else
		return tmp > 0;
}


int Stack[maxn], top;

void Graham() {
	Point p0 = vec[0];
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (p0.y > vec[i].y || p0.y == vec[i].y && p0.x > vec[i].x) {
			p0 = vec[i]; k = i;
		}
	}
	swap(vec[k], vec[0]);
	sort(++vec.begin(), vec.end(), _cmp);
	Stack[0] = 0; top = 0;
	if (n == 1)return;
	Stack[1] = 1; top = 1;
	if (n == 2)return;
	for (int i = 2; i < n; i++) {
		while (top > 0 && cross(vec[Stack[top - 1]], vec[Stack[top]], vec[i]) <= 0)
			top--;
		Stack[++top] = i;
	}
	//cout << top << endl;
}


int main() {
	int l;
	while (~scanf("%d%d", &n, &l)) {
		vec.clear();
		for (int i = 0, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			vec.push_back(Point(x, y));
		}
		Graham();
		double ans = 2.0 * PI * l;
		
		for (int i = 0; i < top; i++) {
			ans += sqrt((double)dist2(vec[Stack[i]], vec[Stack[i + 1]]));
		}
		ans += sqrt((double)dist2(vec[Stack[0]], vec[Stack[top]]));
		printf("%d\n", int(ans + 0.5));
	}
}

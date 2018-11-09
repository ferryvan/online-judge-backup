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
int dist2(Point a, Point b) {
	return (a - b)*(a - b);
}
const int maxn = 50010;
int n;
vector<Point> vec;
int Stack[maxn], top;

bool _cmp(Point p1, Point p2) {
	int tmp = (p1 - vec[0]) ^ (p2 - vec[0]);
	if (tmp > 0) return true;
	else if (tmp == 0 )
		return dist2(p1, vec[0]) <= dist2(p2, vec[0]);
	else return false;
}

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
	Stack[0] = 0; top = 1;
	if (n == 1)return;
	Stack[1] = 1; top = 2;
	if (n == 2)return;
	for (int i = 2; i < n; i++) {
		while (top > 1 &&
			((vec[Stack[top - 1]] - vec[Stack[top - 2]]) ^ (vec[i] - vec[Stack[top - 2]])) <= 0)
			top--;
		Stack[top++] = i;
	}
	//cout << top << endl;
}

int rotating_calipers(Point p[],int n ) {
	int ans = 0;
	int cur = 1;
	for (int i = 0; i < n; i++) {
		Point v = p[i] - p[(i + 1) % n];
		while ((v ^ (p[(cur + 1) % n] - p[cur])) < 0) cur = (cur + 1) % n;
		ans = max(ans, max(dist2(p[i], p[cur]), dist2(p[(i + 1) % n], p[(cur + 1) % n])));
	}
	return ans;
}
Point p[maxn];

int main() {
	while (~scanf("%d", &n)) {
		vec.clear();
		for (int i = 0, x, y; i < n; i++) {
			scanf("%d%d", &x, &y);
			vec.push_back(Point(x, y));
		}
		Graham();
		for (int i = 0; i < top; i++) {
			p[i] = vec[Stack[i]];
			//cout << vec[Stack[i]].x << " " <<vec[Stack[i]].y << endl;
		}
		printf("%d\n", rotating_calipers(p, top));
	}
}
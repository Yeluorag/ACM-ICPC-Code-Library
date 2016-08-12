#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <cmath>
#include <set>
#include <map>
using namespace std;

typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 5e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct Point {
	int x, y;
} p[N], res[N];

bool cmp(Point a, Point b) {
	if(a.x == b.x) return a.y < b.y;
	return a.x < b.x;
}
int cross(Point a, Point b, Point c) {
	return (a.x - c.x) * (b.y - c.y) - (b.x - c.x) * (a.y - c.y);
}

int ConvexHull(Point *p, int n, Point *res) {
	sort(p, p + n, cmp);
	int m = 0;
	for(int i = 0; i < n; i ++) {
		while(m > 1 && cross(res[m - 1], p[i], res[m - 2]) <= 0) m --;
		res[m ++] = p[i];
	}
	int k = m;
	for(int i = n - 2; i >= 0; i --) {
		while(m > k && cross(res[m - 1], p[i], res[m - 2]) <= 0) m --;
		res[m ++] = p[i];
	}
	if(n > 1) m --;
	return m;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	rep(i, n) sii(p[i].x, p[i].y);
    	m = ConvexHull(p, n, res);
    	int ans = 0;
    	rep(i, m) REP(j, i + 1, m)  REP(k, j + 1, m) 
    	ans = max(ans, cross(res[j], res[k], res[i]));
    	printf("%.2lf\n", 0.5 * ans);
    }
    
    return 0;
}
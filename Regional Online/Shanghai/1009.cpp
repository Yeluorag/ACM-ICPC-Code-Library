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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const double Pi = acos(-1);
int T, cas = 0;
int n, m;
struct node
{
	double x, y;
}a, b, c;
double dis(node a, node b) {
	return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	scanf("%lf%lf%lf%lf%lf%lf", &a.x, &a.y, &b.x, &b.y, &c.x, &c.y);
    	double C = dis(a, b), B = dis(a, c), A = dis(b, c);
    	node m;
    	m.x = (b.x + c.x) / 2;
    	m.y = (b.y + c.y) / 2;
    	double H = dis(a, m);
    	double xt = asin(A / 2 / C) * 2;
    	double ans = H + C * xt;
    	printf("Case #%d: %.4lf\n", ++ cas, ans);
    }
    
    return 0;
}
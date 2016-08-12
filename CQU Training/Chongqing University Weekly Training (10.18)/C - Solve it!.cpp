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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int p, q, r, s, t , u;

double fomula(double x) {
	return p * exp(-x) + q * sin(x) + r * cos(x) + s * tan(x) + t * x * x + u;
}

double cal() {
	double l = 0, r = 1, mid, ret = -1;
	if(fomula(l) * fomula(r) > 0) return ret;
	while(r - l > eps) {
		mid = (l + r) / 2;
		if(fomula(mid) * fomula(l) > 0) l = mid;
		else r = mid;
	}
	return ret = mid;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%d%d%d%d%d%d", &p, &q, &r, &s, &t, &u) != EOF) {
    	double ans = cal();
    	if(ans < 0) puts("No solution");
    	else printf("%.4f\n", ans);
    }
    
    return 0;
}
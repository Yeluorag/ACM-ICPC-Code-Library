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
const int inf = 2e9, N = 1e3 + 5, MOD = 1e9 + 7;
const double eps = 1e-9;
int T, cas = 0;
int n, m, k, a, b;

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(a, b) != EOF){
	    if(a >= b) {
	    	double k1 = a + b, k2 = a - b;
	    	int t1 = k1 / 2 / b, t2 = k2 / 2 / b;
	    	double ans = min(k1 / 2 / t1, k2 / 2 / t2);
	    	printf("%.12lf\n", ans);
	    } else puts("-1");
	}
    return 0;
}
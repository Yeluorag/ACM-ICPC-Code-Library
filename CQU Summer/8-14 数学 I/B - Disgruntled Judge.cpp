#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e4 + 1;
const int M = 1e4;

int T, cas = 0;
int n, x[2 * N];

// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    int ok;
    rep(i, T) si(x[i * 2 + 1]);
    FOR(a, 0, M) {
    	FOR(b, 0, M) {
    		ok = 1;
    		for(int i = 2; i <= 2 * T; i ++) {
    			if(i & 1) {
    				if(x[i] != ((a * x[i-1] + b) % MOD)) { ok = 0; break; }
    			} else x[i] = (a * x[i-1] + b) % MOD;
    		}
    		if(ok) break;
    	}
    	if(ok) break;
    }
    rep(i, T) put(x[(i + 1) * 2]);

#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
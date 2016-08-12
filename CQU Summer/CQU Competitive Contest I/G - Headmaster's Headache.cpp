// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
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
#define pb push_back
const int inf = 1 << 25, N = 2e2 + 5, MS = (1 << 9), MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, s, es;
int c[N], tc[N], dp[MS][MS][N];
string in;

// Imp
int dfs(int rest, int opt, int cnt, int now) {
	if(cnt == n + m) {
		if(now == es) return 0;
		else return inf;
	}
	int& ret = dp[opt][now][cnt];
	if(ret >= 0) return ret;
	ret = inf;
	if(cnt >= m) ret = dfs(rest, opt, cnt + 1, now);
	int t1 = tc[cnt] & rest, t2 = tc[cnt] & opt;
	rest ^= t1;
	opt = (opt ^ t2) | t1;
	now |= t2;
	Min(ret, c[cnt] + dfs(rest, opt, cnt + 1, now));
	return ret;
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(s), s) {
    	sii(m, n);
    	es = (1 << s) - 1;
    	mem(dp, -1);
    	mem(tc, 0);
    	getchar();
    	rep(i, m + n) {
    		getline(cin, in);
    		stringstream ss;
    		ss.str(in);
    		ss >> c[i];
    		while(1) {
    			int t;
    			ss >> t;
    			if(ss.fail()) break;
    			tc[i] |= (1 << (t - 1));
    		}
    	}
    	put(dfs(es, 0, 0, 0));
    }

    return 0;
}
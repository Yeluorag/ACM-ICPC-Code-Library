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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, k, cnt, idx, ans;
int x[N], vis[N];
// Imp
void init() {
	cnt = 0;
	idx = 1;
	ans = inf;
	mem(vis, 0);
	rep(i, 4) x[i] = i;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    si(T);
    while(T --) {
    	init();
    	siii(n, m, k);
    	FOR(i, 4, n) x[i] = (x[i-1] + x[i-2] + x[i-3]) % m + 1;
    	FOR(i, 1, n) {
    		vis[x[i]] ++;
    		if(x[i] <=k && vis[x[i]] == 1) cnt ++;
    		while(vis[x[idx]] > 1 || x[idx] > k) vis[x[idx]] --, idx ++;
    		if(cnt == k) Min(ans, i - idx + 1);
    	}

    	printf("Case %d: ", ++ cas);
    	if(ans < inf) put(ans);
    	else puts("sequence nai");
    }
  

    return 0;
}
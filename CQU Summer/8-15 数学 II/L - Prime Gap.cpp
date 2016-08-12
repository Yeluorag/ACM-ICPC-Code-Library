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
const int inf = 0x3f3f3f3f, N = 1300000 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int vis[N], n, ans;
VI primes;
void init() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	for(int i = 2; i <= m; i ++) if(!vis[i])
		for(int j = i * i; j <= N; j += i) vis[j] = 1;
	FOR(i, 2, N) if(!vis[i]) primes.pb(i);
}

// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    init();
    while(~si(n), n) {
    	if(!vis[n]) ans = 0;
    	else {
    		vector<int>:: iterator it;
    		it = lower_bound(ALL(primes), n);
    		ans = *it - *(it - 1);
    	}
    	put(ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
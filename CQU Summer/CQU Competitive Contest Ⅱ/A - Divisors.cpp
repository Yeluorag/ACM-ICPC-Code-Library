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
const int inf = 0x3f3f3f3f, N = 4e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, sz;
int l, u;

// Imp
bool vis[N+1];
vector<int>primes;
void init_primes() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	FOR(i, 2, m) if(!vis[i])
		for(int j = i * i; j <= N; j += i) vis[j] = 1; 
	FOR(i, 2, N) if(!vis[i])
	primes.pb(i);
	sz = primes.size();
}

int solve(int x) {
	int ret = 1;
	rep(i, sz) {
		if(x == 1) break;
		if(primes[i] > x) break;
		int cnt = 1;
		while(x % primes[i] == 0) cnt ++, x /= primes[i];
		ret *= cnt;
	}
	return ret;
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	init_primes();
    si(T);
    while(T --) {
    	sii(l, u);
    	int ans = -1, num = 0;
    	FOR(i, l, u) {
    		int tmp = solve(i);
    		if(tmp > num) {
    			num = tmp;
    			ans = i;
    		}
    	}
    	if(l * u == 1) ans = 1, num = 1;
    	printf("Between %d and %d, %d has a maximum of %d divisors.\n", l, u, ans, num);
    }
    
    return 0;
}
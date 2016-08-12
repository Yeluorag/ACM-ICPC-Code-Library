// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
LL n, m, a, b;
vector<LL> prime;
// Imp
void prime_init(LL n) {
	LL m = (LL)sqrt(n + 0.5);
	for(LL i = 2; i <= m; i ++) if(n % i == 0) {
		while(n % i == 0) n /= i;
		prime.pb(i);
	} if(n > 1) prime.pb(n);
}

LL Inclusion_exclusion(int index, LL b) {
	LL ret = 0, tmp, sz = prime.size();
	REP(i, index, sz) {
		tmp = b / prime[i];
		ret += tmp - Inclusion_exclusion(i + 1, tmp);
	}
	return ret;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    si(T);
    while(T --) {
    	cin >> a >> b >> n;
    	prime.clear();
    	prime_init(n);
    	LL ans = b - a + Inclusion_exclusion(0, a - 1) - Inclusion_exclusion(0, b) + 1;
    	printf("Case #%d: %lld\n", ++ cas, ans);
    }
    
    return 0;
}
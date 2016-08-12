#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cmath>
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
const int inf = 0x3f3f3f3f, N = 1e4+ 5, MOD = 1e9 + 7;

int p, q, r, s, len;
int e[N];
VI prime;
void initPrime() {
	FOR(i, 2, N) {
		int flag = 1;
		for(int j = 2; j * j <= i; j ++)
			if(i % j == 0) { flag = 0; break; }
		if(flag) prime.pb(i);
	}
	len = prime.size();
}

void addInteger(int n, int d) {
	rep(i, len) {
		while(n % prime[i] == 0) {
			n /= prime[i];
			e[i] += d;
		}
		if(n == 1) break;
	}
}

void addFactorial(int n, int d) {
	FOR(i, 1, n) addInteger(i, d);
}

void solve() {
	addFactorial(p, 1);
	addFactorial(q, -1);
	addFactorial(p - q, -1);
	addFactorial(r, -1);
	addFactorial(s, 1);
	addFactorial(r - s, 1);
	double ans = 1;
	rep(i, len) ans *= pow(prime[i], e[i]);
	printf("%.5lf\n", ans);
}
// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    initPrime();
    while(cin >> p >> q >> r >> s) {
    	mem(e, 0);
    	solve();
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
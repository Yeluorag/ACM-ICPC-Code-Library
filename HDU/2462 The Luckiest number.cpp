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
const int inf = 0x3f3f3f3f, N = 5e4 + 5, MOD = 1e9 + 7;
const LL INF = 1e18;
// Macro end

int T, cas = 0;
LL n;

// Imp
bool vis[N];
vector<int>primes;
vector<LL> pri;

LL gcd(LL a, LL b) {
	return !b ? a : gcd(b, a % b);
}

void Init_Primes() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	FOR(i, 2, m) if(!vis[i])
		for(int j = i * i; j <= N; j += i) vis[j] = 1; 
	REP(i, 2, N) if(!vis[i])
	primes.pb(i);
}

LL Euler_Phi(LL n) {
	LL ret = n, m = (LL)sqrt(n + 0.5);
	FOR(i, 2, m) if(n % i == 0) {
		ret = ret / i * (i - 1);
		while(n % i == 0) n /= i;
	} if(n > 1) ret = ret / n * (n - 1);
	return ret;
}

void Phi_Table(int n, int * phi) {
	mem(phi, 0);
	phi[1] = 1;
	FOR(i, 2, n) {
		if(!phi[i]) {
			for(int j = i; j <= n; j += i) {
				if(!phi[j]) phi[j] = j;
				phi[j] = phi[j] / i * (i - 1);
			}
		}
	}
}

LL Mul(LL a, LL b, LL m) {
	LL ret = 0;
	while(b) {
		if(b & 1) ret = (ret + a) % m;
		a = a * 2 % m;
		b >>= 1;
	}
	return ret;
}

LL Pow(LL a, LL b, LL m) {
	LL ret = 1;
	while(b) {
		if(b & 1) ret = Mul(ret, a, m);
		a = Mul(a, a, m);
		b >>= 1;
	}
	return ret;
}

void init(LL n) {
	pri.clear();
	int sz = primes.size();
	rep(i, sz) while(n % (LL)primes[i] == 0) {
		n /= primes[i];
		pri.pb(primes[i]);
	} if(n > 1) pri.pb(n);
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
	Init_Primes();
    while(scanf("%lld", &n) != EOF, n) {
    	LL m = 9 * n / gcd(n, 8LL);
    	if(gcd(m, 10LL) != 1) {
    		printf("Case %d: %d\n", ++ cas, 0);
    		continue;
    	}
    	LL x = Euler_Phi(m);
    	init(x);
    	int sz = pri.size();
    	rep(i, sz) if(Pow(10LL, x / pri[i], m) == 1) x /= pri[i];
    	printf("Case %d: %lld\n", ++ cas, x);
    }

    return 0;
}
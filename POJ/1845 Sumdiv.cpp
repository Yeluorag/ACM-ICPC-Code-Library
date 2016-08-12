// Header.
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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 9901;

int T, cas = 0;
int n, m;
LL a, b;

// Imp
bool vis[N];
vector<int>primes;
void Init_Primes() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	FOR(i, 2, m) if(!vis[i])
		for(int j = i * i; j <= N; j += i) vis[j] = 1; 
	REP(i, 2, N) if(!vis[i])
	primes.pb(i);
}

// Use MulExchange when Pow may be even larger than long long
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

void Work() {
	LL ans = 1;
	for(int i = 0; primes[i] * primes[i] <= a; i ++) {
		if(a % primes[i] == 0) {
			int cnt = 0;
			while(a % primes[i] == 0) {
				cnt ++;
				a /= primes[i];
			}
			LL M = (primes[i] - 1) * MOD;
			ans *= (Pow(primes[i], cnt * b + 1, M) + M - 1) / (primes[i] - 1);
			ans %= MOD;
		}
	}
	if(a > 1) {
		LL M = (a - 1) * MOD;
		ans *= (Pow(a, b + 1, M) + M - 1) / (a - 1);
		ans %= MOD;
	}
	cout << ans << endl;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    Init_Primes();
    while(cin >> a >> b) Work();
    
    return 0;
}
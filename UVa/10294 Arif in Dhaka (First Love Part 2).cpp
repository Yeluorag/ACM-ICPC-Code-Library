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
const int inf = 0x3f3f3f3f, N = 5e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, t;
LL Pow[N];

// Imp

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, t) != EOF) {
    	Pow[0] = 1;
		REP(i, 1, N) Pow[i] = Pow[i - 1] * t;
		LL a = 0;
		rep(i, n) a += Pow[__gcd(i, n)];
		LL b = 0;
		if(n & 1) b = n * Pow[(n + 1) / 2];
		else b = n / 2 * (Pow[n / 2 + 1] + Pow[n / 2]);
		printf("%lld %lld\n", a / n, (a + b) / 2 / n);
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
LL n, m;
vector<int> num;

// Imp
LL gcd(LL a, LL b) {
    return !b ? a : gcd(b, a % b);
}
LL Euler_Phi(LL n) {
    LL ret = n, m = (int)sqrt(n + 0.5);
    for(LL i = 2; i <= m; i ++) if(n % i == 0) {
        ret = ret / i * (i - 1);
        while(n % i == 0) n /= i;
    } if(n > 1) ret = ret / n * (n - 1);
    return ret;
}

bool vis[N];
vector<int>primes;
void Init_Primes() {
    mem(vis, 0);
    int m = sqrt(N + 0.5);
    FOR(i, 2, m) if(!vis[i])
        for(int j = i * i; j < N; j += i) vis[j] = 1;
    REP(i, 2, N) if(!vis[i])
        primes.pb(i);
}

void init(LL n) {
    int sz = primes.size();
    rep(i, sz) while(n % primes[i] == 0) {
        n /= primes[i];
        num.pb(primes[i]);
    } if(n > 1) num.pb(n);
}

LL quick_mod(LL a, LL b, LL mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    Init_Primes();
    while(scanf("%lld", &n) != EOF) {
        num.clear();
        LL ans, x = Euler_Phi(n);
        if(gcd(2LL, n) == 1 && n > 2) {
            init(x);
            int sz = num.size();
            rep(i, sz) if(quick_mod(2LL, x / (LL)num[i], n) == 1) x /= num[i];
            ans = x;
        } else ans = -1;
        if(ans == -1) printf("2^? mod %lld = 1\n", n);
        else printf("2^%lld mod %lld = 1\n", ans, n);
    }
    
    return 0;
}
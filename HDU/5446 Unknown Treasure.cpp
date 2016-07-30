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
int k;
LL t[15], p[15];

// Imp
void exgcd(LL a, LL b, LL &d, LL &x, LL &y) {
    if(b == 0) {
        d = a, x = 1, y = 0;
    } else {
        exgcd(b, a % b, d, y, x);
        y -= x * (a / b);
    }
}

LL Mul(LL a, LL b, LL mod) {
    LL ret = 0;
    while(b) {
        if(b & 1)    ret = (ret + a) % mod;
        a = (a + a) % mod;
        b >>= 1;
    }
    return ret;
}

LL quick_mod(LL a, LL b, LL mod) {
    LL ret = 1;
    a %= mod;
    while(b) {
        if(b & 1) ret = ret * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return ret;
}


LL Cm(LL n, LL m, LL p) {
    if(m > n) return 0;
    LL ret = 1;
    for(LL i = 1; i <= m; i ++) {
        LL a = (n + i - m) % p;
        LL b = i % p;
        ret = ret * (a * quick_mod(b, p - 2, p) % p) % p;
    }
    return ret;
}

LL Lucas(LL n, LL m, LL p) {
    if(m == 0) return 1;
    return Cm(n % p, m % p, p) * Lucas(n / p, m / p, p) % p;
}

LL CRT(LL a[], LL m[], int n) {
    LL M = 1, ans = 0;
    rep(i, n) M *= m[i];
    rep(i, n) {
        LL x, y, d;
        LL Mi = M / m[i];
        exgcd(m[i], Mi, d, x, y);
        LL tmp = Mul(y, Mi, M);
        ans = (ans + Mul(tmp, a[i], M)) % M;
    }
    return (ans + M) % M;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        cin >> n >> m;
        si(k);
        rep(i, k) {
            scanf("%lld", &p[i]);
            t[i] = Lucas(n, m, p[i]);
        }
        printf("%lld\n", CRT(t, p, k));
    }
    
    return 0;
}
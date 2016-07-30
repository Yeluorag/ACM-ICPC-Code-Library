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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k, p, idx = 1;
bool prime[N];
int inv[N][N], fac[N][N], hs[N];
// Imp
bool vis[N];
vector<int>primes;
void Init_Primes() {
    mem(vis, 0);
    mem(hs, 0);
    int m = sqrt(N + 0.5);
    primes.pb(1);
    REP(i, 2, N) if(!vis[i]){
        hs[i] = idx ++;
        primes.pb(i);
        for(int j = i * i; j < N; j += i) vis[j] = 1;
    }
}

int Quick_mod(int a, int b, int m) {
    int ret = 1;
    a %= m;
    while(b) {
        if(b & 1) ret = ret * a % m, b --;
        b >>= 1;
        a = a * a % m;
    }
    return ret;
}

void init() {
    int sz = primes.size();
    REP(i, 1, primes.size()) {
        fac[i][0] = inv[i][0] = 1;
        REP(j, 1, primes[i]) {
            fac[i][j] = (fac[i][j - 1] * j) % primes[i];
            inv[i][j] = Quick_mod(fac[i][j], primes[i] - 2, primes[i]);
        }
    }
}

int Cm(int n, int m) {
    if(m > n) return 0;
    if(m == n) return 1;
    int pn = hs[p];
    return fac[pn][n] * (inv[pn][n - m] * inv[pn][m] % p) % p;
}

int Lucas(int n, int m) {
    if(m == 0) return 1;
    return Cm(n % p, m % p) * Lucas(n / p, m / p) % p;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    Init_Primes();
    init();
    while(siii(n, k, p) != EOF) {
        if(k > n - k) k = n - k;
        printf("Case #%d: %d\n", ++ cas, (Lucas(n + 1, k) % p + n - k) % p);
    }
    
    return 0;
}
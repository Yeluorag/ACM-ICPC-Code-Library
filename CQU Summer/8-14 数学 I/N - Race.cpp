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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 10056;

int T, cas = 0;
int n, f[N], C[N][N];

void Combo() {
    mem(C, 0);
    rep(i, N) {
        C[i][0] = 1;
        FOR(j, 1, i)
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
}

void init() {
    Combo();
    f[0] = 1;
    REP(i, 1, N) {
        f[i] = 0;
        FOR(j, 1, i) {
            f[i] = (f[i] + C[i][j] * f[i-j] % MOD) % MOD;
        }
    }
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    si(T);
    while(T --) {
        si(n);
        printf("Case %d: %d\n", ++ cas, f[n]);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
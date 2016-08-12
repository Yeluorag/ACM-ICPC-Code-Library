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
const int inf = 0x3f3f3f3f, N = 95, M = 4e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
LL t, n;
int k;
LL C[M][M];
struct  Matrix {
    LL m[N][N];
    Matrix() { mem(m, 0); }
} A;
// Imp
void init() {
    mem(C, 0);
    FOR(i, 0, k) {
        C[i][0] = C[i][i] = 1;
        REP(j, 1, i)
        C[i][j] = (C[i-1][j-1] + C[i-1][j]) % MOD;
    }
}

Matrix multi(Matrix a, Matrix b) {
    Matrix c;
    rep(i, n) {
        rep(j, n) {
            rep(k, n) {
                c.m[i][j] += a.m[i][k] * b.m[k][j];
                c.m[i][j] %= MOD;
            }
        }
    }
    return c;
}


Matrix power(Matrix base, LL t) {
    Matrix x;
    for (int i = 0; i < n; i++) x.m[i][i] = 1;
    
    while (t) {
        if (t & 1) x = multi(x, base);
        base = multi(base, base);
        t /= 2;
    }
    return x;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    while(cin >> t >> k) {
        n = 2 * k + 3;
        init();
        Matrix ret;
        FOR(i, 0, k) FOR(j, 0, i) ret.m[i][j] = ret.m[i + k + 1][j] = ret.m[i][j + k + 1] = C[i][j];
        ret.m[2 * k + 2][k] = ret.m[2 * k + 2][2 * k + 2] = 1;
        
        Matrix Ans = power(ret, t);
        LL ans = 0;
        rep(i, 2 * k + 2) {
            ans += Ans.m[2 * k + 2][i];
            ans %= MOD;
        }
        cout << ans << endl;
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    return 0;
}
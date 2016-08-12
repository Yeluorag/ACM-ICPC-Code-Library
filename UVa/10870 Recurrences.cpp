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
const int inf = 0x3f3f3f3f, N = 20 + 5, MOD = 1e9 + 7;
typedef vector<LL> vec;
typedef vector<vec> mat;
int T, cas = 0;
int n, m, d;
int a[N], f[N];

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int k = 0; k < B.size(); k ++) {
            for(int j = 0; j < B[0].size(); j ++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % m;
            }
        }
    }
    return C;
}

mat pow(mat A, LL n) {
    mat B(A.size(), vec(A.size()));
    for(int i = 0; i < A.size(); i ++) B[i][i] = 1;
    while(n > 0) {
        if(n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(siii(d, n, m), d + n + m) {
        rep(i, d) si(a[i]);
        FOR(i, 1, d) si(f[i]);
        mat A(d, vec(d));
        rep(i, d) A[0][i] = a[i];
        REP(i, 1, d) rep(j, d) A[i][j] = i == j + 1;
        A = pow(A, n - d);
        LL ans = 0;
        if(n <= d) ans = f[n];
        else rep(i, d) ans = (ans + A[0][i] * (LL)f[d - i]) % m;
        printf("%lld\n", ans);
    }
    
    return 0;
}

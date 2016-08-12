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
const double a = 5.0 + 2 * (sqrt(6));
typedef vector<LL> vec;
typedef vector<vec> mat;

int T, cas = 0;
int n, m, M;
LL x;
// Imp

mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for(int i = 0; i < A.size(); i ++) {
        for(int k = 0; k < B.size(); k ++) {
            for(int j = 0; j < B[0].size(); j ++) {
                C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % M;
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

LL quick_mod(LL a, LL b, int m) {
    LL ret = 1;
    while(b > 0) {
        if(b & 1) ret = ret * (LL)a  % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    si(T);
    while(T--) {
        mat A(2, vec(2));
        A[0][0] = 5, A[0][1] = 12;
        A[1][0] = 2, A[1][1] = 5;
        scanf("%lld%d", &x, &M);
        LL Mod = (M + 1) * (M - 1);
        LL k = quick_mod(2LL, x, Mod) + 1;
        A = pow(A, k);
        int ans = (2 * A[0][0] + M - 1) % M;
        printf("Case #%d: %d\n", ++ cas, ans);
    }
    
    return 0;
}
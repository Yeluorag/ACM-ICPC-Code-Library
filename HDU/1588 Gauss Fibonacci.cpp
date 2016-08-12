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

Mat I, A, K, A0;
LL k, b, n, M;
// Imp
struct Mat {
    LL matrix[sz][sz];
};
const int sz = 2;
Mat Add(Mat a, Mat b) {
    Mat c;
    rep(i, sz) rep(j, sz) c.matrix[i][j] = (a.matrix[i][j] + b.matrix[i][j]) % M;
    return c;
}

Mat Mul(Mat a, Mat b) {
    Mat c;
    rep(i, sz) {
        rep(j, sz) {
            c.matrix[i][j] = 0;
            rep(k, sz) {
                c.matrix[i][j] += (a.matrix[i][k] * b.matrix[k][j]) % M;
                c.matrix[i][j] %= M;
            }
        }
    }
    return c;
}

Mat Pow(Mat a, LL x) {
    Mat ret = I;
    while(x > 0) {
        if(x & 1) ret = Mul(ret, a);
        a = Mul(a, a);
        x >>= 1;
    }
    return ret;
}

Mat Work(Mat a, LL x) {
    if(x == 1) return a;
    else if(x & 1) return Add(Pow(a, x), Work(a, x - 1));
    else return Mul(Work(a, x >> 1), Add(Pow(a, x >> 1), I));
}

Mat Init_I() {
    Mat ret;
    rep(i, sz) rep(j, sz) ret.matrix[i][j] = i == j;
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    A.matrix[0][0] = 1;
    A.matrix[0][1] = 1;
    A.matrix[1][0] = 1;
    A.matrix[1][1] = 0;
    I = Init_I();
    
    while(scanf("%lld%lld%lld%lld", &k, &b, &n, &M) != EOF) {
        K = Pow(A, k);
        A0 = I;
        A0 = Add(A0, Work(K, n - 1));
        if(b != 0) {
            Mat tmp = Pow(A, b);
            A0 = Mul(tmp, A0);
        }
        printf("%lld\n", A0.matrix[0][1] % M);
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, d, k;
int a[N], b[N];
typedef vector<LL> vec;
typedef vector<vec> mat;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    rep(i, n) rep(j, n) C[0][i] = (C[0][i] + A[0][i] * B[j][i]) % m; 
    REP(i, 1, n) rep(j, n) C[i][j] = C[0][(n + j - i) % n];
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


// 求t内与n不互质的个数 - 容斥原理
// prime[n]: vector, n的素因子
// ans = n / 2 + n / 3 + n / 5 - n / (2 * 3) - n / (2 * 5) - n / (3 * 5) + n / (2 * 3 * 5) ......
int Inclusion_exclusion(int index, int t, int n) {
    int ret = 0, tmp;
    int sz = prime[n].size();
    REP(i, index, sz) {
        tmp = t / prime[n][i];
        ret += tmp - cal(i + 1, tmp, n);
    }
    return ret;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%d%d%d%d", &n, &m, &d, &k) != EOF) {
    	mat A_(1, vec(n));
    	rep(i, n) si(a[i]), A_[0][i] = a[i];
    	mat A(n, vec(n));
    	A[0][0] = 1;
    	FOR(i, 1, d) A[0][(i + n) % n] = A[0][(n - i) % n] = 1;
    	A = pow(A, k);
    	A_ = mul(A, A_);
    	rep(i, n - 1) printf("%lld ", A_[0][i]);
    	printf("%lld\n", A_[0][n - 1]);
    }
    
    return 0;
}

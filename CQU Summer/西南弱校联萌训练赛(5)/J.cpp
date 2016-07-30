// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
LL n, m;
typedef vector<int> vec;
typedef vector<vec> mat;
mat A(2, vec(2));
// Imp
mat Mul(mat& A, mat& B) {
	mat C(A.size(), vec(B[0].size()));
	rep(i, A.size()) {
		rep(k, B.size()) {
			rep(j, B[0].size()) {
				C[i][j] = (C[i][j] + A[i][k] * B[k][j]) % MOD;
			}
		}
	}
	return C;
}

mat Pow(mat A, LL n) {
	mat B(A.size(), vec(A.size()));
	rep(i, A.size()) B[i][i] = 1;
	while(n > 0) {
		if(n & 1) B = Mul(B, A);
		A = Mul(A, A);
		n >>= 1;
	}
	return B;
}

void init() {
	A[0][0] = 3, A[0][1] = 1;
	A[1][0] = 1, A[1][1] = 0;
}

void solve() {
	A = Pow(A, n);
	LL g = A[1][0];
	init();
	A = Pow(A, g);
	g = A[1][0];
	init();
	A = Pow(A, g);
	cout << A[1][0] << endl;
}


#define LOCAL
int main(){
#ifdef LOCAL
    IN // OUT
#endif
	
    while(scanf("%lld", &n) != EOF) solve();
    
    return 0;
}
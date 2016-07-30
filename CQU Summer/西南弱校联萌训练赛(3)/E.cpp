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
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 9901;
// Macro end

int T, cas = 0;
int n, d;
int a[N], dp[N];
// Imp
struct SparseTable{
	static const int MaxLength = N;
	int f[MaxLength][20];
	int (*cp) (int, int);

	void build(int *a, int n, int (*func) (int, int)) {
		for(int i = 0; i <= n - 1; i ++) f[i][0] = a[i];
		cp = func;
		for(int k = 1; (1 << k) <= n; k ++)
			for(int i = 0; i + (1 << k) <= n; i ++) {
				int len = 1 << (k - 1);
				f[i][k] = func (f[i][k-1], f[i+len][k-1]);
			}
	}

	int query(int L, int R) {
		int len = R - L + 1, k = 0;
		while((1 << k) < len) k ++;
		if(k) k --; len = (1 << k);
		return cp(f[L][k], f[R-len+1][k]);
	}
};
inline int MIN(int x, int y) {
	return x < y ? x : y;
}

int GCD(int x, int y) {
	return y == 0? x : GCD(y, x % y);
}
SparseTable minST, gcdST;
int Pow(int a, int n) {
	if(n == 0) return 1;
	int x = Pow(a, n / 2);
	int ans = x * x % MOD;
	if(n & 1) ans = ans * a % MOD;
	return ans;
}

int dfs(int l, int r) {
	int ret = 0;
	bool flag = 1;
	REP(i, l, r) {
		if(abs(a[i+1] - a[i]) <= d) {
			flag = 0;
			ret = (ret + (2 * (dfs(l, i) +  dfs(i + 1, r))) % MOD) % MOD;
		}
	}
	if(flag) return Pow(2, r - l + 1);
	return ret;
}

#define LOCAL
int main(){
#ifdef LOCAL
    IN;
//  OUT;
#endif
	
	while(sii(n, d) != EOF) {
		rep(i, n) si(a[i]);
		int ans = dfs(0, n - 1) - n - 1;
		put(ans); 
	}
    
    
    return 0;
}
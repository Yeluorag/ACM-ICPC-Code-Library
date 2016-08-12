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
const int inf = 0x3f3f3f3f, N = 150000 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, q, k;
int query[105], ans[105];
struct door {
	int tm, p;
}dos;
struct node {
	int id, v;
}guy[N];
int guy[N];
map<string, int> que;
map<string, int> mp;
map<int, string> pm;
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

inline int MAX(int x, int y) {
	return x > y ? x : y;
}

bool cmp(door a, door b) {
	return a.tm < b.tm;
}
// Imp
void solve() {
	SparseTable maxST;
	maxST.build(guy, k, MAX);
	map<int, int> di;
	sort(dos, dos + m, cmp);
	rep(i, m) {
		di[dos[i].tm - 1] = i;
		if(i == 0) di[dos[i].tm - 1] = -1;
	}
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	si(T);
	while(T --) {
		mp.clear();
		pm.clear();
		sii(k, m, q);
		char s[205];
		int val, tm;
		rep(i, k) {
			scanf("%s", s);
			si(guy[i]);
			mp[s] = i;
			pm[i] = s;
		}
		rep(i, m) {
			sii(tm, val);
			dos[i].tm = tm;
			dos[i].p = val;
		}
		rep(i, q) si(q[i]);
	}
    
    
    return 0;
}
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// ------------------------------------------Macro-------------------------------------------
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
#define db double
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;
// ----------------------------------------Macro End-----------------------------------------

int T, cas = 0;
int n;
double d[N][N];
struct node{
	int x, y, z, r;
}m[N], a, b;

void read() {
	rep(i, n + 2) {
		if(i < n) siii(m[i].x, m[i].y, m[i].z), si(m[i].r);
		else siii(m[i].x, m[i].y, m[i].z), m[i].r = 0;
	} n += 2;
}

void floyd() {
	rep(i, n) rep(j, n) {
		if(i == j) d[i][j] = 0;
		else {
			double dist = sqrt((db)(m[i].x - m[j].x) * (m[i].x - m[j].x) + 
						   	   (db)(m[i].y - m[j].y) * (m[i].y - m[j].y) + 
						       (db)(m[i].z - m[j].z) * (m[i].z - m[j].z));
			if(dist <= m[i].r + m[j].r) d[i][j] = 0;
			else d[i][j] = dist - m[i].r - m[j].r;
		}
	}

	rep(k, n) rep(i, n) rep(j, n) Min(d[i][j], d[i][k] + d[k][j]);
}

void solve() {
	read(), floyd();
	printf("Cheese %d: Travel time = %.0lf sec\n", ++ cas, d[n-2][n-1] * 10);
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
// -----------------------------------------Main Pro-----------------------------------------


    while(~si(n), n + 1) solve();nn


// --------------------------------------------End-------------------------------------------    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 4e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int r[N][N], b[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	sii(n, m);
	mem(r, 0x3f), mem(b, 0x3f);
	for(int i = 1; i <= n; i ++) r[i][i] = b[i][i] = 0;
	int u, v;
	for(int i = 0; i < m; i ++) {
		sii(u, v);
		r[u][v] = r[v][u] = 1;
	}
	for(int i = 1; i <= n; i ++)
		for(int j = 1; j <= n; j ++) 
			if(i != j && r[i][j] == inf) b[i][j] = 1;
	
	for(int k = 1; k <= n; k ++)
		for(int i = 1; i <= n; i ++)
			for(int j = 1; j <= n; j ++) {
				r[i][j] = min(r[i][j], r[i][k] + r[k][j]);
				b[i][j] = min(b[i][j], b[i][k] + b[k][j]);
			}

	int ans = max(r[1][n], b[1][n]);
	if(ans == inf) ans = -1;
	printf("%d\n", ans);
    
    return 0;
}
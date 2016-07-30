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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], b[N][N], dp[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	mem(a, 0), mem(b, 0), mem(dp, 0);
    	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
    		si(a[i][j]);
    		a[i][j] += a[i][j-1];
    	}
    	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
    		si(b[i][j]);
    		b[i][j] += b[i-1][j];
    	}

    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= m; j ++) {
    			dp[i][j] = max(dp[i-1][j] + a[i][j], dp[i][j-1] + b[i][j]);
    		}
    	}
		printf("Case %d: %d\n", ++ cas, dp[n][m]);
    }
    
    return 0;
}
/*
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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], b[N][N], dp[N][N];

int dfs(int x, int y) {
	int& ret = dp[x][y];
	if(x * y == 0) return 0;
	if(~ret) return ret;
	ret = max(ret, dfs(x - 1, y) + a[x][y]);
	ret = max(ret, dfs(x, y - 1) + b[x][y]);
	return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	mem(a, 0), mem(b, 0), mem(dp, -1);
    	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
    		si(a[i][j]);
    		a[i][j] += a[i][j-1];
    	}
    	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
    		si(b[i][j]);
    		b[i][j] += b[i-1][j];
    	}
    	printf("Case %d: %d\n", ++ cas, dfs(n, m));
    }
    
    return 0;
}
*/
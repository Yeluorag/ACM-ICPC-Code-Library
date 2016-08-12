
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
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, last;
int a[N][N], dp[N][N];

int dfs(int x, int y) {
	int& ret = dp[x][y];
	if(ret < inf) return ret;
	if(x == 1 && y == 1) return ret = 0;
	if(x > 1) {
		if((x + y) & 1) ret = min(ret, dfs(x - 1, y) + a[x][y] * a[x-1][y]);
		else ret = min(ret, dfs(x - 1, y));
	}
	if(y > 1) {
		if((x + y) & 1) ret = min(ret, dfs(x, y - 1) + a[x][y] * a[x][y-1]);
		else ret = min(ret, dfs(x, y - 1));
	}
	return ret;
}
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, m) != EOF) {
        for(int i = 1; i <= n; i ++) 
    		for(int j = 1; j <= m; j ++)
    			si(a[i][j]);
        mem(dp, 0x3f);
        printf("%d\n", dfs(n, m));
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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], a[N][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	mem(dp, 0x3f);
    while(sii(n, m) != EOF) {
    	for(int i = 1; i <= n; i ++) 
    		for(int j = 1; j <= m; j ++)
    			si(a[i][j]);
    	dp[1][0] = dp[0][1] = 0;
    	for(int i = 1; i <= n; i ++) {
    		for(int j = 1; j <= m; j ++) {
    			if((i + j) & 1) dp[i][j] = min(dp[i-1][j] + a[i-1][j] * a[i][j], 
    				dp[i][j-1] + a[i][j-1] * a[i][j]);
    			else dp[i][j] = min(dp[i-1][j], dp[i][j-1]);
    		}
    	}
    	printf("%d\n", dp[n][m]);
    }

    
    return 0;
}
*/
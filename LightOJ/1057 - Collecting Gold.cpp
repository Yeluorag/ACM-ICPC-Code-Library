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
const int inf = 0x3f3f3f3f, N = 20 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, sz;
int st, ed;
vector<int> x, y;
char maz[N][N];
int dp[1<<17][N];

int Dis(int x, int y) { return max(abs(x), abs(y)); }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, m);
    	for(int i = 1; i <= n; i ++) scanf("%s", maz[i] + 1);
    	x.clear(), y.clear();
    	mem(dp, 0x3f);
    	for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
    		if(maz[i][j] == 'g') x.pb(i), y.pb(j);
    		if(maz[i][j] == 'x') st = x.size(), x.pb(i), y.pb(j);
    	}
    	dp[0][st] = 0;
    	sz = x.size();
    	int Lim = (1 << sz) - 1;
    	for(int s = 0; s <= Lim; s ++) {
    		for(int i = 0; i < sz; i ++) {
    			if((1 << i) & s) continue;
    			int newState = s | (1 << i);
    			for(int j = 0; j < sz; j ++)
    				dp[newState][j] = min(dp[newState][j], dp[s][i] + Dis(x[i] - x[j], y[i] - y[j]));
    		}
    	}
    	printf("Case %d: %d\n", ++ cas, dp[Lim][st]);

    }
    
    return 0;
}
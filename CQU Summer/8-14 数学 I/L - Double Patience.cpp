#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
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
const int inf = 0x3f3f3f3f, N = 2e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int vis[N];
double dp[N];
char card[9][5][3];

void Mem() { mem(dp, 0);  mem(vis, 0); }

double dfs(int n) {
	if(!n) return 1.0;
	if(vis[n]) return dp[n];
	vis[n] = 1;
	int a[10], tmp = n, cnt = 0;

	for(int i = 0; i < 9; i ++) {
		a[i] = tmp % 5;
		tmp /= 5;
	}

	rep(i, 9) REP(j, i + 1, 9) 
	if(a[i] && a[j] && card[i][a[i]][0] == card[j][a[j]][0]) {
		tmp = 0;
		for(int k = 8; k >= 0; k --) tmp = tmp * 5 + a[k] - (k == i || k == j);
		dp[n] += dfs(tmp);
		cnt ++;
	}
	
	if(cnt) dp[n] /= (double)cnt;
	return dp[n];
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    while(~ss(card[0][1])){
    	Mem();
    	REP(i, 2, 5) ss(card[0][i]);
    	REP(i, 1, 9) REP(j, 1, 5) ss(card[i][j]);
    	double ans = dfs(1953124);
    	printf("%.6lf\n", ans);
    }
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
#define LOCAL
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i >= t; i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 41, MOD = 1e9 + 7;

int T, cas = 0;
int n, x[4][N], idx[4], cnt[N], dp[N][N][N][N];

int dfs(int num, int cnt[]) {
	int& dt = dp[idx[0]][idx[1]][idx[2]][idx[3]];
	if(dt > -1) return dt;
	if(num == 5) return dt = 0;
	int ret = 0;
	rep(i, 4) {
		if(idx[i] == n) continue;
		idx[i] ++;
		int tmp = x[i][idx[i]];
		cnt[tmp] = !cnt[tmp];
		if(!cnt[tmp]) ret = max(ret, dfs(num - 1, cnt) + 1);
		else ret = max(ret, dfs(num + 1, cnt));
		cnt[tmp] = !cnt[tmp];
		idx[i] --;
	}
	return dt = ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n), n) {
    	mem(x, 0); mem(idx, 0); mem(cnt, 0); mem(dp, -1);
    	rep(i, n) rep(j, 4) si(x[j][i]);
    	printf("%d\n", dfs(0, cnt));
    }
    
    return 0;
}
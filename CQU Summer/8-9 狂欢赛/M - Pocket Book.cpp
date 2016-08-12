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
const int inf = 1 << 30, N = 1e2 + 5, MOD = 1e9 + 7;

int n, m, flag[N][30],cnt[N];
LL ans = 0;
char bk[N][N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    mem(cnt, 0);
    mem(flag, 0);
    sii(n, m);
    rep(i, n) ss(bk[i]);
    rep(i, m) {
    	rep(j, n) {
    		if(!flag[i][bk[j][i] - 'A']) {
    			flag[i][bk[j][i] - 'A'] = 1;
    			cnt[i] ++;
    		}
    	}
    }
    rep(i, m) ans = (ans * cnt[i]) % MOD;
    cout << ans << endl;
    return 0;
}
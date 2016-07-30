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
const int inf = 0x3f3f3f3f, N = (1 << 16) + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, flag[20][20], dp[N];
struct node{
    int x, y;
}a[20];

bool check(node b, node c, node d) { return (d.x - b.x) * (c.y - b.y) == (d.y- b.y) * (c.x - b.x); }

void init() {
    mem(flag, 0);
    mem(dp, 0x3f);
    rep(i, n) {
        REP(j, i + 1, n) {
            flag[i][j] = (1 << i) | (1 << j);
            rep(k, n) {
                if(check(a[i], a[j], a[k]))
                    flag[i][j] |= (1 << k);
            }
        }
    }
}

int dfs(int s) {
    if(dp[s] < inf) return dp[s];
    int cnt = __builtin_popcount(s);
    if(!cnt) return dp[s] = 0;
    if(cnt < 3) dp[s] = 1;
    
    rep(i, n) {
        if(!(s & (1 << i))) continue;
        REP (j, i + 1, n) {
            if(!(s & (1 << j))) continue;
            dp[s] = min(dp[s], dfs(s ^ (s & flag[i][j])) + 1);
        }
        break;
    }
    return dp[s];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        si(n);
        rep(i, n) sii(a[i].x, a[i].y);
        init();
        printf("Case %d: %d\n", ++ cas, dfs((1 << n) - 1));
    }
    
    return 0;
}
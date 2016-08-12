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
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 12, MOD = 1e9 + 7;

int s, n, idx, st[N], a[N][105], dp[2005][N];

void Mem() { mem(dp, -1); }

bool cmp(int i, int j) {
    if(st[i] == st[j]) return a[i][st[i]-1] < a[j][st[j]-1];
    return st[i] < st[j];
}

bool dfs(int sum, int cnt) {
    if(dp[sum][cnt] != -1) return dp[sum][cnt];
    if(!sum) return dp[sum][cnt] = true;
    if(!cnt) return dp[sum][cnt] = false;
    rep(i, st[idx])  if(sum >= a[idx][i] && dfs(sum - a[idx][i], cnt -1)) return dp[sum][cnt] = true;
    return dp[sum][cnt] = false;
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(s), s) {
        si(n);
        rep(i, n) { si(st[i]); rep(j, st[i]) si(a[i][j]); }
        int ans = -1, ca = 0;
        for(idx = 0; idx < n; idx ++) {
            Mem();
            int res = -1;
            FOR(i, 1, 2005) {
                if(dfs(i, s)) res = i;
                else break;
            }
            if(res > ans) ans = res, ca = idx;
            if(res == ans && cmp(idx, ca)) ca = idx;
        } printf("max coverage =%4d :", ans); rep(i, st[ca]) printf("%3d", a[ca][i]);
        ET;
    }
    
    return 0;
}
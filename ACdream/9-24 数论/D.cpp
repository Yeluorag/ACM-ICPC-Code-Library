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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, len;
char a[N];
// Imp
vector<int> num;
int vis[55], ans,flag[1005], cnt[15];
int b[4];

void init() {
    mem(flag, 0);
    for(int i = 0; i < 1001; i += 8) flag[i] = 1;
}
void dfs(int cur) {
    if(cur == 3 || cur == len) {
        int tmp = 0;
        rep(i, cur) tmp = tmp * 10 + b[i];
        if(flag[tmp]) ans = 1;
        return;
    }
    int sz = num.size();
    rep(i, sz) {
        if(vis[i]) continue;
        vis[i] = 1;
        b[cur] = num[i];
        dfs(cur + 1);
        vis[i] = 0;
    }
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    while(scanf("%s", a) != EOF) {
        len = strlen(a);
        mem(b, 0);
        ans = 0;
        num.clear();
        mem(vis, 0);
        mem(cnt, 0);
        rep(i, len) cnt[a[i] - '0'] ++;
        if(cnt[0] > 2) ans = 1;
        rep(i, 10) {
            int t = 0;
            while(cnt[i] && t < 3) {
                cnt[i] --;
                t ++;
                num.pb(i);
            }
        }
        dfs(0);
        printf("%s\n", ans ? "YES" : "NO");
    }
    
    return 0;
}
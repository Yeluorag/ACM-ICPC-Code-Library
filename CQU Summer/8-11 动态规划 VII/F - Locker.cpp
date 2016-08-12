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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
int T, cas = 0;
int len, dp[N][11][11];
int a[N], b[N];
char s1[N], s2[N];

void Mem() { mem(dp, 0x3f); mem(a, 0); mem(b, 0);}
int dfs(int a0, int a1, int idx) {
    int& ret = dp[idx][a0][a1], cnt;
    if(idx >= len) return ret = 0;
    if(ret < inf) return ret;
    
    cnt = (b[idx] + 10 - a0) % 10;
    FOR(i, 0, cnt) FOR(j, i, cnt)
    ret = min(ret, dfs((a1 + j) % 10, (a[idx+2] + i) % 10, idx + 1) + cnt);
    
    cnt = (a0 + 10 - b[idx]) % 10;
    FOR(i, 0, cnt) FOR(j, i, cnt)
    ret = min(ret, dfs((a1 + 10 - j) % 10, (a[idx+2] + 10 - i) % 10, idx + 1) + cnt);
    
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(ss(s1) != EOF) {
        Mem();
        ss(s2); len = strlen(s1);
        rep(i, len) a[i] = s1[i] - '0', b[i] = s2[i] - '0';
        printf("%d\n", dfs(a[0], a[1], 0));
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
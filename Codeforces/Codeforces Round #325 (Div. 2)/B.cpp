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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[3][N], b[N];
int sum[3][N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    int ans = inf;
    mem(sum, 0);
    FOR(i, 1, 2) FOR(j, 2, n) si(a[i][j]);
    
    FOR(j, 2, n) sum[1][j] = sum[1][j - 1] + a[1][j];
    for(int j = n - 1; j >= 1; j --) sum[2][j] = sum[2][j + 1] + a[2][j + 1];
    FOR(i, 1, n) si(b[i]);
    FOR(g, 1, n) {
        FOR(s, 1, n) {
            if(g == s) continue;
            int tmp = sum[1][g] + sum[2][g] + b[g] + sum[1][s] + sum[2][s] + b[s];
            ans = min(ans, tmp);
        }
    }
    printf("%d\n", ans);
    return 0;
}
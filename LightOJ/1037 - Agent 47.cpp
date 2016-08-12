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
const int inf = 0x3f3f3f3f, N = 6e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, Lim;
int dp[N], a[N][20];
int hp[20], maz[20][20];

int dfs(int s) {
    if(~dp[s]) return dp[s];
    if(s == 0) return dp[s] = 0;
    dp[s] = inf;
    for(int i = 0; i < n; i ++) {
        if((1 << i) & s) {
            int newState = s - (1 << i);
            dp[s] = min(dp[s], dfs(newState) + (hp[i] + a[newState][i] - 1) / a[newState][i]);
        }
    }
    return dp[s];
}

void init() {
    Lim = (1 << n) - 1;
    for(int s = 0; s <= Lim; s ++) {
        for(int i = 0; i < n; i ++) {
            if((1 << i) & s) {
                int newState = s - (1 << i);
                for(int j = 0; j < n; j ++) {
                    a[s][j] = max(a[newState][j], maz[i][j]); 
                }
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//    freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        si(n);
        mem(dp, -1), mem(a, 0);
        for(int i = 0; i < n; i ++) {
            si(hp[i]);
            a[0][i] = 1;
        }
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j < n; j ++) {
                scanf("%1d", &maz[i][j]);
            }
        }
        init();
        printf("Case %d: %d\n", ++ cas, dfs(Lim));
    }
    
    return 0;
}
// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, c;
int dp[10005], cnt[15][15];
// Imp
// Use Last Group
void ZeroOne_Pack(int weight, int value, int n) {
    for(int i = n; i >= weight; i --)
        dp[i] = max(dp[i], dp[i-weight] + value);
}
// Use This Group
void Complete_Pack(int weight, int value, int n) {
    for(int i = weight; i <= n; i ++)
        dp[i] = max(dp[i], dp[i-weight] + value);
}
// n: Number of Group, m: Total Weight of Pack
int Multi_Pack(int w[], int v[], int num[], int n, int m) {
    mem(dp, 0);
    for(int i = 1; i <= n; i ++) {
        if(num[i] * w[i] > m)
            Complete_Pack(w[i], v[i], m);
        else {
            int k = 1;
            while(k < num[i]) {
                ZeroOne_Pack(k * w[i], k * v[i], m);
                num[i] -= k;
                k <<= 1;
            }
            ZeroOne_Pack(num[i] * w[i], num[i] * v[i], m);
        }
    }
    return dp[m];
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    while(sii(n, c) != EOF) {
        mem(cnt, 0);
        mem(dp, 0);
        char str[15];
        int a, b;
        
        rep(i, n) {
            ss(str);
            sii(a, b);
            cnt[a][b] ++;
        }
        int w[105], v[105], num[105];
        int idx = 0;
        mem(w, 0), mem(v, 0), mem(num, 0);
        FOR(i, 0, 10) {
            FOR(j, 0, 10) {
                if(cnt[i][j]) {
                    num[idx] = cnt[i][j];
                    w[idx] = j;
                    v[idx] = i;
                    idx ++;
                }
            }
        }
        printf("%d\n", Multi_Pack(w, v, num, idx, c));
    }
    
    return 0;
}
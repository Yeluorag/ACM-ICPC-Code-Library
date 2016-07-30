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
const int inf = 0x3f3f3f3f, N = 90 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int l, r, k;
int bit[20];
int dp[20][N][N];

int dfs(int len, int mod1, int mod2, bool flag) {
    if(len == -1) return mod1 == 0 && mod2 == 0;
    if(!flag && dp[len][mod1][mod2] != -1)
        return dp[len][mod1][mod2];
    int ret = 0;
    int ed = flag ? bit[len] : 9;
    for(int i = 0; i <= ed; i ++) {
        int m1 = (mod1 * 10 + i) % k, m2 = (mod2 + i) % k;
        ret += dfs(len - 1, m1, m2, flag && i == ed);
    }
    if(!flag) dp[len][mod1][mod2] = ret;
    return ret;
}

int cal(int x) {
    int tot = 0;
    while(x) {
        bit[tot ++] = x % 10;
        x /= 10;
    }
    return dfs(tot - 1, 0, 0, true);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//    freopen("/Users/apple/out.txt", "w", stdout);
#endif
   
    si(T);
    while(T --) {
        siii(l, r, k);
        mem(dp, -1);
        printf("Case %d: ", ++ cas);
        if(k > 90) {
            puts("0");
            continue;
        }
        printf("%d\n", cal(r) - cal(l - 1));
    }
    
    return 0;
}

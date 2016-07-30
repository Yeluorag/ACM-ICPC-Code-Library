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

typedef unsigned long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, x;
LL dp[30][N], p[30];
LL gcd(LL a, LL b) {
    return b ? gcd(b, a % b) : a;
}

void init() {
    p[0] = 1;
    for(int i = 1; i <= 25; i ++) p[i] = p[i-1] * 6;
    mem(dp, 0);
    dp[0][0] = 1;    
    for(int i = 1; i <= 25; i ++) {
        for(int j = 1; j <= i * 6; j ++) {
            for(int k = 1; k <= 6; k ++)
                if(k <= j) dp[i][j] += dp[i-1][j-k];
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    init();
    si(T);
    while(T --) {
        sii(n, x);
        LL ans = 0;
        for(int i = x; i <= n * 6; i ++) ans += dp[n][i];
        printf("Case %d: ", ++ cas);
        if(ans == 0 || ans == p[n]) {
            printf("%lld\n", ans / p[n]);
            continue;
        }
        printf("%lld/%lld\n", ans / gcd(ans, p[n]), p[n] / gcd(ans, p[n]));
    }
    
    return 0;
}

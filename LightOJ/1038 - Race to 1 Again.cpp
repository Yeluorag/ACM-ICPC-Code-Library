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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
double dp[N];

void init() {
    mem(dp, 0);
    for(int i = 2; i < N; i ++) {
        int cnt = 0;
        double sum = 0;
        for(int j = 1; j * j <= i; j ++) {
            if(i % j == 0) {
                sum += dp[j] + dp[i / j];
                cnt += 2;
                if(j * j == i) sum -= dp[j], cnt --;
            }
        }
        dp[i] = (sum + cnt) / (cnt - 1);
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
        si(n);
        printf("Case %d: %.6f\n", ++ cas, dp[n]);
    }
    
    return 0;
}
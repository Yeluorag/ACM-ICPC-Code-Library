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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N][3], l[N], r[N], ans;
char maz[N][N];
bool isa(char c) { return (c == 'w' || c == 'y' || c == 'z' || c == 'a'); }
bool isb(char c) { return (c == 'w' || c == 'x' || c == 'z' || c == 'b'); }
bool isc(char c) { return (c == 'x' || c == 'y' || c == 'z' || c == 'c'); }
void work(int i, int idx) {
    dp[i][0][idx] = dp[i][m+1][idx] = -1;
    for(int j = 1; j <= m; j ++) l[j] = r[j] = j;
    for(int j = 1; j <= m; j ++) {
        while(dp[i][l[j] - 1][idx] >= dp[i][j][idx])
            l[j] = l[l[j] - 1];
    }
    for(int j = m; j > 0; j --) {
        while(dp[i][r[j] + 1][idx] >= dp[i][j][idx])
            r[j] = r[r[j] + 1];
    }
    for(int j = 1; j <= m; j ++) ans = max(ans, (r[j] - l[j] + 1) * dp[i][j][idx]);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
   	while(sii(n, m) != EOF) {
        ans = 0;
        for(int i = 1; i <= n ; i ++) scanf("%s", maz[i] + 1);
        mem(dp, 0);
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) {
                if(isa(maz[i][j])) dp[i][j][0] = dp[i-1][j][0] + 1;
                if(isb(maz[i][j])) dp[i][j][1] = dp[i-1][j][1] + 1;
                if(isc(maz[i][j])) dp[i][j][2] = dp[i-1][j][2] + 1;
            }
            work(i, 0);
            work(i, 1);
            work(i, 2);
        }
        printf("%d\n", ans);
   	}
    
    return 0;
}
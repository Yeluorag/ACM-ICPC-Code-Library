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
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 35, MOD = 1e9 + 7;

int T, cas = 0;
LL dp[N][N], cnt[N][N];
char a[N], b[N];
void Mem() { mem(dp, 0); mem(cnt, 0); }
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);getchar();
    while(T--) {
        gets(a);
        gets(b);
        Mem();
        int n = strlen(a), m = strlen(b);
        FOR(i, 0, n) cnt[i][0] = 1;
        FOR(i, 0, m) cnt[0][i] = 1;
        FOR(i, 1, n) FOR(j, 1, m) {
            if(a[i-1] == b[j-1]) {
                dp[i][j] = dp[i-1][j-1] + 1;
                cnt[i][j] = cnt[i-1][j-1];
            } else {
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
                if(dp[i][j-1] == dp[i-1][j]) cnt[i][j] = cnt[i-1][j] + cnt[i][j-1];
                else if(dp[i-1][j] > dp[i][j-1]) cnt[i][j] = cnt[i-1][j];
                else cnt[i][j] = cnt[i][j-1];
            }
        }
        printf("Case #%d: %lld %lld\n", ++ cas, n + m - dp[n][m], cnt[n][m]);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
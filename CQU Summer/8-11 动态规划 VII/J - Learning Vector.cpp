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
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 5e1 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k, sum, ans, dp[N][N * N];
struct node{
    int x, y;
    int cal() { return x * y; }
}a[N];

void init() { mem(dp, -0x3f); dp[0][0] = 0; ans = 0; }

bool cmp(node a, node b) {
    if(a.y * b.x != a.x * b.y) return a.y * b.x > a.x * b.y;
    return a.x > b.x;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        init();
        sii(n, k);
        rep(i, n) sii(a[i].x, a[i].y);
        sort(a, a + n, cmp);
        
        rep(i, n) for(int j = N * N - 1; j >= a[i].y; j --) for(int t = k; t > 0; t --)
        if(dp[t-1][j-a[i].y] >= 0) Max(dp[t][j], dp[t-1][j-a[i].y] + 2 * a[i].x * (j - a[i].y) + a[i].cal());
        
        for(int i = N * N - 1; i >= 0; i --) Max(ans, dp[k][i]);
        printf("Case %d: %d\n", ++ cas, ans);
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
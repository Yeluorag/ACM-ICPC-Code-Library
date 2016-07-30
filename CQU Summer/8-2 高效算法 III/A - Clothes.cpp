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
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = t; i < n; i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 100 + 5;

int n, m, a[N], u[N], v[N], g[N][N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> n >> m;
    mem(g, 0);
    int ans = inf;
    rep(i, n) scanf("%d", &a[i]);
    rep(i, m) {
        int a, b;
        scanf("%d%d", &a, &b);
        g[a-1][b-1] = g[b-1][a-1] = 1;
    }
    rep(i, n) rep(j, n) rep(k, n)
        if(g[i][j] && g[j][k] && g[k][i]){
            ans = min(ans, a[i] + a[j] + a[k]);
        }
    printf("%d\n", ans == inf ? -1 : ans);
    return 0;
}
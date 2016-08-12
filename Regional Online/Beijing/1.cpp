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
double dis[N][N];
struct point {
    double x, y;
    int id;
}a[N];
// Imp
double Dis(point p, point q) {
    return sqrt((p.x - q.x) * (p.x - q.x) + (p.y - q.y) * (p.y - q.y));
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        mem(dis, 0);
        sii(m, n);
        rep(i, m) {
            scanf("%lf%lf", &a[i].x, &a[i].y);
            a[i].id = i;
        }
        int ans = inf;
        rep(i, m) {
            dis[i][i] = 0;
            REP(j, i + 1, m) {
                dis[i][j] = dis[j][i] = Dis(a[i], a[j]);
            }
            sort(dis[i], dis[i] + m);
            double mx = dis[i][n - 1];
            int r = floor(mx) + 1;
            if(dis[i][n] > r * 1.0 || n == m) ans = min(ans, r);
        }
        if(ans == inf) ans = -1;
        printf("%d\n", ans);
        
    }
    
    return 0;
}
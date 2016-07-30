#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define VD vector<double>
#define PII pair<int, int>
#define pb push_back
const int inf = 1 << 30;
const int N = 20000 + 5;

int T, cas = 0;
int n, idx, rk[N];
double a[N][3], score[N];
VD v[N];
void init(int j, double sum) {
    v[idx].pb(sum);
    REP(i, j, 3)  init(i + 1, sum + a[idx][i]);
}

bool cmp(double a, double b) { return a > b; }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(scanf("%d", &n), n) {
        int ans = 1;
        mem(score, -1);
        rep(i, N) v[i].clear();
        REP(i, 1, n + 1) {
            scanf("%lf%lf%lf", &a[i][0], &a[i][1], &a[i][2]);
            idx = i; init(0, 0);
            sort(ALL(v[i]), cmp);
        }
        REP(i, 1, n + 1) scanf("%d", &rk[i]);
        score[0] = inf;
        REP(i, 1, n + 1) {
            ans = 0;
            int r = rk[i];
            rep(j, v[r].size()) {
                if(v[r][j] - score[i - 1] > 1e-6) continue;
                if(abs(v[r][j] - score[i-1]) < 1e-6 && r < rk[i-1]) continue;
                ans = 1;
                score[i] = v[r][j];
                break;
            }
            if(!ans) break;
        }
        printf("Case %d: ", ++ cas);
        if(!ans) puts("No solution");
        else printf("%.2lf\n", score[n]);
    }
    
    return 0;
}
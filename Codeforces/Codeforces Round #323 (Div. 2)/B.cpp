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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, cnt, ans = 0, pos, now, dir;
int a[N], vis[N];
// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    pos = 1;
    dir = 1;
    cnt = 0;
    now = 1;
    mem(vis, 0);
    si(n);
    FOR(i, 1, n) si(a[i]);
    while(cnt < n) {
        if(dir == 1) {
            for(int i = 1; i <= n; i ++) {
                if(!vis[i] && cnt >= a[i]) {
                    cnt ++;
                    vis[i] = 1;
                }
                if(i == n) {
                    dir = -1;
                    if(cnt < n)  {
                        ans ++;
                    }
                }
            }
        } else {
            for(int i = n; i > 0; i --) {
                if(!vis[i] && cnt >= a[i]) {
                    cnt ++;
                    vis[i] = 1;
                }
                if(i == 1) {
                    dir = 1;
                    if(cnt < n) {
                        ans ++;
                    }
                }
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}
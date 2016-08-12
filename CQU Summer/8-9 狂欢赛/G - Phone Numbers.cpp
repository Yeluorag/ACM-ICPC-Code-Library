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
#define si(a) scanf("%d", &a)
#define ss(a) scanf("%s", a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e2 + 5, MOD = 1e9 + 7;

int n, s[N], t[N], p[N], g[N];
char nam[N][N], tmp[10];
vector<char *> txi, piz, grl;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(n);
    mem(t, 0);
    mem(p, 0);
    mem(g, 0);
    int mt = -1, mp = -1, mg = -1;
    rep(i, n) {
        si(s[i]); ss(nam[i]);
        rep(j, s[i]) {
            ss(tmp);
            int f1 = 1, f2 = 1, last = tmp[0];
            for(int i = 1; i < strlen(tmp); i ++) {
                if(tmp[i] == '-') continue;
                
                if(tmp[i] >= last) f2 = 0;
                if(tmp[i] != last) f1 = 0;
                last = tmp[i];
            }
            if(f1) t[i] ++;
            else if(f2) p[i] ++;
            if(!f1 && !f2) g[i] ++;
        }
        mt = max(mt, t[i]);
        mp = max(mp, p[i]);
        mg = max(mg, g[i]);
    }
    rep(i, n) {
        if(t[i] == mt) txi.pb(nam[i]);
        if(p[i] == mp) piz.pb(nam[i]);
        if(g[i] == mg) grl.pb(nam[i]);
    }
    printf("If you want to call a taxi, you should call:");
    rep(i, txi.size()) printf(" %s%c", txi[i], i == txi.size() - 1 ? '.' : ','); ET;
    printf("If you want to order a pizza, you should call:");
    rep(i, piz.size()) printf(" %s%c", piz[i], i == piz.size() - 1 ? '.' : ','); ET;
    printf("If you want to go to a cafe with a wonderful girl, you should call:");
    rep(i, grl.size()) printf(" %s%c", grl[i], i == grl.size() - 1 ? '.' : ','); ET;
    return 0;
}
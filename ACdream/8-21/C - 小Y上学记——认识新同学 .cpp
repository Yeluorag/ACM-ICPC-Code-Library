// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
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
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, a[N];
int p[N];
struct edge{
    int u, v, w;
    edge() {}
    edge(int x, int y, int z) {
        u = x, v = y, w = z;
    }
    bool operator < (const edge& rhs) const {
        return w < rhs.w;
    }
}e[N * N];
// Imp
int find(int x) { return x == p[x] ? x : p[x] = find(p[x]); }
int Kruskal(int x) {
    int ans = 0;
    FOR(i, 0, n) p[i] = i;
    FOR(i, x, m) {
        int u = e[i].u, v = e[i].v, w = e[i].w;
        int x = find(u), y = find(v);
        if(x != y) {
            p[x] = y;
            ans += w;
        }
    }
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    int t, tot;
    while(si(n) != EOF) {
        tot = 0;
        int ret = 0;
        n --;
        m = n * n;
        FOR(i, 1, n) si(a[i]);
        FOR(i, 1, n) FOR(j, 1, n) {
            si(t);
            if(i == j) e[tot++] = edge(0, i, a[i]);
            else e[tot++] = edge(i, j, t);
        } sort(e, e + tot);
        ret = Kruskal(0);
        put(ret);
    }  
    
    return 0;
}
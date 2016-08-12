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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, k;
int in[N], head[3 * N], nxt[3 * N], to[3 * N];
int ans[N];
struct edge{
    int to, nxt;
}a[3 * N];
int ne;
// Imp
void addEdge(int u, int v) {
    to[ne] = v;
    in[v] ++;
    nxt[ne] = head[u];
    head[u] = ne ++;
}
bool topo() {
    int i, j;
    for(j = 0; j < n; j ++) {
        for(i = 0; i < n; i ++) {
            if(!in[i]) {
                in[i] --;
                ans[j] = i;
                for(int l = head[i]; l != -1; l = nxt[l])
                    in[to[l]] --;
                break;
            }
        }
        if(i >= n) break;
    }
    if(j >= k) return true;
    return false;
}

// #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    int u, v;
    while(siii(n, m, k) != EOF) {
        ne = 1;
        mem(head, -1);
        mem(in, 0);
        rep(i, m) {
            sii(u, v);
            addEdge(u, v);
        }
        if(topo()) {
            rep(i, k - 1) printf("%d ", ans[i]);
            printf("%d\n", ans[k-1]);
        }
        else puts("-1");
    }
    
    return 0;
}
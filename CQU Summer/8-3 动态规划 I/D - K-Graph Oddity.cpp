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
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
const int inf = 1 << 30;
const int N = 100000 + 5;

int n, m, k, cnt, cas = 0;
int p[2 * N], nxt[2 * N], head[N], vis[N], deg[N], c[N];

void add_edge(int u, int v) {
    p[cnt] = v;
    nxt[cnt] = head[u];
    head[u] = cnt ++;
}

void dfs(int u) {
    for(int i = head[u]; ~i; i =nxt[i]) {
        int v = p[i];
        vis[c[v]] = u;
    }
    FOR(i, 1, k) if(vis[i] != u) { c[u] = i; break; }
    for(int i = head[u]; ~i; i = nxt[i]) {
        int v = p[i];
        if(c[v]) continue;
        dfs(v);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    while(scanf("%d%d", &n, &m) != EOF) {
        if(cas ++) puts("");
        k = 0;
        cnt = 0;
        mem(c, 0);
        mem(deg, 0);
        mem(head, -1);
        rep(i, m) {
            int a, b;
            scanf("%d%d", &a, &b);
            add_edge(a, b); add_edge(b, a);
            k = max(k, max(++ deg[a], ++ deg[b]));
        }
        if(k % 2 == 0) k ++;
        dfs(1);
        printf("%d\n", k);
        FOR(i, 1, n) printf("%d\n", c[i]);
    }
    return 0;
}
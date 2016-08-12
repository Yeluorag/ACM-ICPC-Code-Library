// Header.
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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct edge{
    int v, next;
}e[300005];
int ne, head[N];
void InitEdge() {
    ne = 0;
    mem(head, -1);
}
void addEdge(int u, int v) {
    e[ne].v = v;
    e[ne].next = head[u];
    head[u] = ne ++;
    e[ne].v = u;
    e[ne].next = head[v];
    head[v] = ne ++;
}
int degree[N], vis[N], p[N], in[N], cnt;
LL sum = 0;
vector<int> ponds;
// Imp
void init() {
    mem(degree, 0);
    mem(vis, 0);
    mem(in, 0);
    ponds.clear();
}


void solve() {
    queue<int> que;
    int sz = ponds.size();
    rep(i, sz) {
        que.push(ponds[i]);
        in[ponds[i]] = 1;
    }
    while(!que.empty()) {
        int u = que.front(); que.pop();
        in[u] = 1;
        if(degree[u] > 0) degree[u] --;
        for(int i = head[u]; i != -1; i = e[i].next) {
            int v = e[i].v;
            if(degree[v] > 0) degree[v] --;
            if(degree[v] <= 1 && !in[v]) {
                in[v] = 1;
                que.push(v);
            }
        }
    }
}

void dfs(int u) {
    sum += LL(p[u]);
    cnt ++;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(vis[v]) continue;
        vis[v] = 1;
        dfs(v);
    }
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        init();
        InitEdge();
        sii(n, m);
        FOR(i, 1, n) si(p[i]);
        int u, v;
        rep(i, m) {
            sii(u, v);
            addEdge(u, v);
            degree[u] ++;
            degree[v] ++;
        }
        FOR(i, 1, n) if(degree[i] <= 1) ponds.pb(i);
        solve();
        LL ans = 0;
        FOR(i, 1, n) if(degree[i] <= 0) vis[i] = 1;
        FOR(i, 1, n) {
            cnt = 0;
            sum = 0;
            if(!vis[i]) {
                vis[i] = 1;
                dfs(i);
                if(cnt & 1) ans += sum;
            }
        }
        cout << ans << endl;
    }
    
    return 0;
}
// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
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
int n, m;
struct edge {
    int v, next;
}e[5 * N];
int ne, head[N];
void addEdge(int u, int v) {
    e[ne].v = v;
    e[ne].next = head[u];
    head[u] = ne ++;
    e[ne].v = u;
    e[ne].next = head[v];
    head[v] = ne ++;
}
int dfsnum;
int degree[N], dfn[N], low[N];
bool exist[N][N];
// Imp
void init() {
    ne = 0;
    mem(degree, 0);
    mem(head, -1);
    mem(dfn, 0);
    mem(exist, false);
}

void Tarjan(int u, int fa) {
    dfn[u] = low[u] = ++ dfsnum;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v == fa) continue;
        if(!dfn[v]) {
            Tarjan(v, u);
            Min(low[u], low[v]);
            if(low[v] > dfn[u]) exist[u][v] = exist[v][u] = true;
        } else Min(low[u], dfn[v]);
    }
}

int cc[N], ccCnt;
void dfs(int u, int fa) {
    cc[u] = ccCnt;
    for(int i = head[u]; i != -1; i = e[i].next) {
        int v = e[i].v;
        if(v != fa && !exist[u][v] && !cc[v])
            dfs(v, u);
    }
}

int work() {
    mem(cc, 0); ccCnt = 1;
    FOR(i, 1, n) {
        if(!cc[i]) {
            dfs(i, -1);
            ccCnt ++;
        }
    }
    FOR(i, 1, n) {
        int u = i;
        for(int j = head[i]; j != -1; j = e[j].next) {
            int v = e[j].v;
            if(cc[u] != cc[v]) degree[cc[u]] ++;
        }
    }
    int ret = 0;
    REP(i, 1, ccCnt) ret += degree[i] == 1;
    return (ret + 1) / 2;
}

int main(){
#ifdef LOCAL
    IN // OUT
#endif
    
    while(sii(n, m) != EOF) {
        init();
        int u, v;
        rep(i, m) {
            sii(u, v);
            addEdge(u, v);
        }
        
        dfsnum = 0;
        
        Tarjan(1, -1);
        put(work());
    }
    
    return 0;
}
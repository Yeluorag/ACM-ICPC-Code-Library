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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int high, low, dist[N], Maxlen, ed;
vector<int> son[N];
vector<int> best, worst;

void dfs(int u, int fa, int deep) {
    if(deep > Maxlen) Maxlen = deep, ed = u;
    int sz = son[u].size();
    for(int i = 0; i < sz; i ++) {
        int v = son[u][i];
        if(v != fa) {
            dfs(v, u, deep + 1);
            dist[v] = max(dist[v], deep + 1);
        }
    }
}

void init() {
    Maxlen = 0;
    high = -1;
    low = inf;
    mem(dist, 0);
    best.clear(), worst.clear();
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
 //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(si(n) != EOF) {
        int x; 
        init();
        best.clear(), worst.clear();
        for(int i = 1; i <= n; i ++) {
            si(m);
            son[i].clear();
            for(int j = 0; j < m; j ++) {
                si(x);
                son[i].pb(x);
            }
        }
        dfs(1, -1, 0);
        dfs(ed, -1, 0);
        dfs(ed, -1, 0);
        for(int i = 1; i <= n; i ++) high = max(high, dist[i]), low = min(low, dist[i]);
        for(int i = 1; i <= n; i ++) {
            // printf("%d's deep: %d\n", i, dist[i]);
            if(dist[i] == high) worst.pb(i);
            if(dist[i] == low) best.pb(i);
        }
        sort(ALL(best)), sort(ALL(worst));
        printf("Best Roots  :");
        for(int i = 0; i < best.size(); i ++) printf(" %d", best[i]); puts("");
        printf("Worst Roots :");
        for(int i = 0; i < worst.size(); i ++) printf(" %d", worst[i]); puts("");
    }
    
    return 0;
}
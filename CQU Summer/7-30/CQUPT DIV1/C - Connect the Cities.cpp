#include <iostream>
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
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int maxn = 500 + 5;

int T, n, m, k;
int d[maxn][maxn], tmp[maxn], vis[maxn], mincost[maxn];

int prim() {
    int ans = 0, cnt = 0;
    for(int i = 1; i <= n; i ++) mincost[i] = inf;
    mincost[1] = 0;
    while(1) {
        int u = -1;
        for(int v = 1; v <= n; v ++) {
            if(mincost[v] == inf) continue;
            if(!vis[v] && (u == -1 || mincost[v] < mincost[u])) u = v;
        }
        if(u == -1) break;
        vis[u] = 1;
        cnt ++;
        ans += mincost[u];
        for(int v = 1; v <= n; v ++){
            if(d[v][u] == inf) continue;
            mincost[v] = min(mincost[v], d[v][u]);
        }
        
    }
    if(cnt < n) ans = -1;
    return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        int a, b, c;
        mem(vis, 0);
        scanf("%d%d%d", &n, &m, &k);
        for(int i = 0; i <= n; i ++) {
            for(int j = 0; j <= n; j ++)
                d[i][j] = inf;
            d[i][i] = 0;
        }
        
        for(int i = 0; i < m; i ++) {
            scanf("%d%d%d", &a, &b, &c);
            if(c < d[a][b]) d[a][b] = d[b][a] = c;
        }
        for(int i = 0; i < k; i ++) {
            int t;
            scanf("%d", &t);
            for(int j = 0; j < t; j ++) scanf("%d", &tmp[j]);
            for(int j = 0; j < t; j ++)
                for(int l = j + 1; l < t; l ++)
                    d[tmp[j]][tmp[l]] = d[tmp[l]][tmp[j]] = 0;
        }
        printf("%d\n", prim());
    }
    
    return 0;
}
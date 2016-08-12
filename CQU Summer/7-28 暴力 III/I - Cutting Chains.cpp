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
const int maxn = 20 + 5;

int g[maxn][maxn], vis[maxn];
int cnt, n, ans, cas = 1;

bool check(int num) {
    for(int i = 0; i < n; i++) {
        int ct = 0;
        if(num & (1 << i)) continue;
        for(int j = 0; j < n; j++) {
            if(num & (1 << j)) continue;
            if(g[i][j]) ct ++;
        }
        if(ct > 2) return true;
    }
    return false;
}

bool dfs(int num, int cur, int last) {
    vis[cur] = 1;
    for(int i = 0; i < n; i++) {
        if(!g[cur][i] || (num & (1 << i)) || i == last) continue;
        if(vis[i] || dfs(num, i, cur)) return true;
    }
    return false;
}

bool isCircle(int num) {
    for(int i = 0; i < n; i++) {
        if(vis[i] || (num & (1 << i))) continue;
        cnt ++;
        if(dfs(num, i, -1)) return true;
    }
    return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    while(scanf("%d", &n), n) {
        int a, b;
        mem(g, 0);
        ans = inf;
        while(scanf("%d%d", &a, &b) != EOF) {
            if(a == -1 && b == -1) break;
            g[a-1][b-1] = g[b-1][a-1] = 1;
        }
        for(int i = 0; i < (1 << n); i++) {
            cnt = 0;
            mem(vis,0);
            if(check(i) || isCircle(i)) continue;
            if(__builtin_popcount(i) >= cnt - 1)
                ans = min(ans, __builtin_popcount(i));
        }
        printf("Set %d: Minimum links to open is %d\n", cas ++, ans);
    }	
    return 0;
}

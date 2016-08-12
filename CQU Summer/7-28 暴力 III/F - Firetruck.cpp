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

int e, a, b, res, num, cas = 1, vis[25], flag[25], ans[25], g[25][25];

void init(int u) {
    flag[u] = 1;
    for(int i = 1; i < 22; i++) {
        if(!flag[i] && g[u][i])
            init(i);
        
    }
}
void dfs(int now, int cur) {
    if(now == e) {
        for(int i = 0; i < cur - 1; i++) printf("%d ", ans[i]);
        printf("%d\n", ans[cur-1]);
        res ++;
        return;
    }
    for(int i = 1; i < 22; i++) {
        if(!vis[i] && flag[i] && g[now][i]){
            vis[i] = 1;
            ans[cur] = i;
            dfs(i, cur + 1);
            vis[i] = 0;
        }
    }
}
int main(){
//    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    while(scanf("%d", &e) != EOF) {
        num = -1;
        res = 0;
        memset(g, 0, sizeof(g));
        memset(flag, 0, sizeof(flag));
        memset(vis, 0, sizeof(vis));
        while(scanf("%d%d", &a, &b) && a && b) {
            g[a][b] = g[b][a] = 1;
            num = max(max(num, a), b);
        }
        printf("CASE %d:\n", cas++);
        init(e);
        vis[1] = 1;
        ans[0] = 1;
        dfs(1, 1);
        printf("There are %d routes from the firestation to streetcorner %d.\n", res, e);
    }
    return 0;
}
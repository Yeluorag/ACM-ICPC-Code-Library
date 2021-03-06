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
const int maxn = 1000 + 5;

int n, m, ans;
int g[maxn][maxn], vis[maxn];

void dfs(int u) {
	if(vis[u]) return;
	vis[u] = 1;
	for(int i = 1; i <= n; i ++) {
		if(g[u][i] && !vis[i]) {
			dfs(i);
		}
	}
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    while(scanf("%d%d", &n, &m), n) {
    	mem(g, 0);
    	mem(vis, 0);
    	ans = 0;
    	int a, b;
    	for(int i = 0; i < m; i ++) {
    		scanf("%d%d", &a, &b);
    		g[a][b] = g[b][a] = 1;
    	}
    	for(int i = 1; i <= n; i ++) {
    		if(!vis[i]) {
    			ans++;
    			dfs(i);
    		}
    	}
    	printf("%d\n", ans - 1);

    }
    
    return 0;
}
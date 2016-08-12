#define LOCAL
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
const int maxn = 100 + 5;

int n;
int d[maxn][maxn], vis[maxn], mincost[maxn];
int prim() {
	int ans = 0;
	mem(vis, 0);
	mem(mincost, 0x3f);
	mincost[1] = 0;
	for(int i = 0; i < n; i ++) {
		int u = -1;
		for(int j = 1; j <= n; j ++) 
			if(!vis[j] && (u == -1 || mincost[j] < mincost[u])) u = j;
		// if(u == -1) break;
		vis[u] = 1;
		ans += mincost[u];
		for(int j = 1; j <= n; j ++) 
			mincost[j] = min(mincost[j], d[u][j]);
	}
	return ans;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    while(scanf("%d", &n) != EOF) {
    	for(int i = 1; i <= n; i ++)
    		for(int j = 1; j <= n; j ++)
    			scanf("%d", &d[i][j]);
    	printf("%d\n", prim());
    }
    
    return 0;
}
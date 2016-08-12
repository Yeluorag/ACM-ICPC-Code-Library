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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int vis[N];
double sy, gy;
struct Circle {
	int x, y, r;
}c[N];

bool check(Circle a, Circle b) {
	return (a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y) - (a.r + b.r) * (a.r + b.r) <= 0;
}

bool dfs(int u) {
	vis[u] = 1;
	if(c[u].y - c[u].r <= 0) return false;
	if(c[u].x - c[u].r <= 0) sy = min(sy, c[u].y - sqrt(c[u].r * c[u].r - c[u].x * c[u].x));
	if(c[u].x + c[u].r - 1000 >= 0) gy = min(gy, c[u].y - sqrt(c[u].r * c[u].r - (1000 - c[u].x) * (1000 - c[u].x)));
	for(int i = 0; i < n; i ++) {
		if(vis[i]) continue;
		if(check(c[u], c[i])) {
			if(!dfs(i)) return false;
		}
	}
	return true;
}

void work() {
	sy = gy = 1000;
	for(int i = 0; i < n; i ++) {
		if(!vis[i] && c[i].y + c[i].r >= 1000) {
			if(!dfs(i)) {
				printf("IMPOSSIBLE\n");
				return;
			}
		}
	}
	printf("0.00 %.2lf 1000.00 %.2lf\n", sy, gy);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) == 1) {
    	mem(vis, 0);
    	for(int i = 0; i < n; i ++) siii(c[i].x, c[i].y, c[i].r);
    	work();
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;

// Imp
int ans = 0;
int v1, v2;
int link[N];
bool grid[N][N], vis[N];

bool find(int x) {
	FOR(y, 1, v2) {
		if(grid[x][y] && !vis[y]) {
			vis[y] = 1;
			if(link[y] == 0 || find(link[y])) {
				link[y] = x;
				return true;
			}
		}
	}
	return false;
}

void search() {
	FOR(i, 1, v1) {
		mem(vis, 0);
		if(find(i)) ans ++; 
	}
}

void read() {
    int x, y;
    v1 = v2 = n;
    FOR(i, 1, m) sii(x, y) , grid[x][y] = 1;
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	ans = 0;
    	read();
    	search();
    	printf("%d\n", ans);
    }
    
    return 0;
}
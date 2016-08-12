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
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N], b[N];
int ans = 0;
int link[N];
bool grid[N][N], vis[N];

bool find(int x) {
	FOR(y, 1, m) {
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
	ans = 0;
	FOR(i, 1, n) {
		mem(vis, 0);
		if(find(i)) ans ++; 
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n); FOR(i, 1, n) si(a[i]);
    	si(m); FOR(i, 1, m) si(b[i]);
    	mem(grid, 0);
    	mem(link, 0);
    	FOR(i, 1, n) FOR(j ,1, m) if((a[i] && b[j] % a[i] == 0) || !b[j]) grid[i][j] = 1;

    	search();
    	printf("Case %d: %d\n", ++ cas, ans);
    }
    
    return 0;
}
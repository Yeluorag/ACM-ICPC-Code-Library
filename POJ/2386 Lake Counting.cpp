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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ans;
char field[N][N];
void dfs(int x, int y) {
	field[x][y] = '.';
	for(int i = -1; i <= 1; i ++) {
		for(int j = -1; j <= 1; j ++) {
			int nx = x + i, ny = y + j;
			if(nx >= 0 && nx < n && ny >= 0 && ny < m && field[nx][ny] == 'W')
				dfs(nx, ny);
		}
	}
}

void solve() {
	int res = 0;
	for(int i = 0; i < n; i ++) {
		for(int j = 0; j < m; j ++) {
			if(field[i][j] == 'W') 
				res ++, dfs(i, j);
		}
	}
	printf("%d\n", res);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    sii(n, m);
    for(int i = 0; i < n; i ++) scanf("%s", field[i]);
    solve();
    
    return 0;
}
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
int n, m, p, ne, ans, tmp;
char maz[N][N];
struct rose {
	int x, y;
}a[N];
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };
void dfs(int cur) {
	if(cur == ne) {

	}
	for(int i = 0; i < 4; i ++) {
		int 
	}
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(siii(n, m, p) != EOF) {
    	ne = ans = tmp = 0;
    	for(int i = 0; i < n; i ++) { 
    		scanf("%s", maz[i]);
    		for(int j = 0; j < m; j ++) if(maz[i][j] == '*') {
    			a[ne].x = i;
    			a[ne].y = j;
    			ne ++;
    		}

    	}
    }
    
    return 0;
}
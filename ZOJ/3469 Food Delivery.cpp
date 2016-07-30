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
int x0, v, st, sum[N];
int dp[N][N][2];
struct node {
	int x, b;
}a[N];
bool cmp(node a, node b) { return a.x < b.x; }
int min(int a, int b, int c) { return min(a, min(b, c)); }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(siii(n, v, x0) != EOF) {
    	mem(sum, 0);
    	mem(dp, 0x3f);
    	for(int i = 1; i <= n; i ++) sii(a[i].x, a[i].b);
    	n ++; a[n].x = x0, a[n].b = 0;
    	sort(a + 1, a + n + 1, cmp);
   		for(int i = 1; i <= n; i ++) { 
   			sum[i] = sum[i-1] + a[i].b;
   			if(a[i].x == x0) st = i;
   		}

   		dp[st][st][0] = dp[st][st][1] = 0;
   		for(int i = st; i >= 1; i --) {
   			for(int j = st; j <= n; j ++) {
   				int tmp = sum[i-1] + sum[n] - sum[j];
   				if(i == j) continue;
   				dp[i][j][0] = min(dp[i][j][0], dp[i+1][j][0] + (tmp + a[i].b) * (a[i+1].x - a[i].x), 
   						 dp[i+1][j][1] + (tmp + a[i].b) * (a[j].x - a[i].x));
   				dp[i][j][1] = min(dp[i][j][1], dp[i][j-1][1] + (tmp + a[j].b) * (a[j].x - a[j-1].x),
   						 dp[i][j-1][0] + (tmp + a[j].b) * (a[j].x - a[i].x));
   			}
   		}

   		printf("%d\n", min(dp[1][n][0], dp[1][n][1]) * v);
    }
    
    return 0;
}
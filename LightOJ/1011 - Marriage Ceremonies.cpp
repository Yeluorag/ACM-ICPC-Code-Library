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
const int inf = 0x3f3f3f3f, N = 17, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int a[N][N], dp[N][1 << N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < n; i ++) 
    		for(int j = 0; j < n; j ++) 
    			si(a[i][j]);
    	mem(dp, 0);
    	for(int i = 0; i < n; i ++) dp[0][1 << i] = a[0][i];
    	int all = (1 << n) - 1;
    	for(int i = 1; i < n; i ++) {
    		for(int s = 0; s <= all; s ++) {
    			if(!dp[i-1][s]) continue;
    			for(int j = 0; j < n; j ++) {
    				if(s & (1 << j)) continue;
    				dp[i][s|(1 << j)] = max(dp[i][s|(1 << j)], dp[i-1][s] + a[i][j]);
    			}
    		}
    	}
    	printf("Case %d: %d\n", ++ cas, dp[n-1][all]);
    }
    
    return 0;
}
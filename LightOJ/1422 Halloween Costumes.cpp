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
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], c[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < n; i ++) si(c[i]);
    	mem(dp, 0);
    	for(int i = 0; i < n; i ++) dp[i][i] = 1;
    	for(int j = 1; j < n; j ++) {
    		for(int i = j - 1; i >= 0; i --) {
    			dp[i][j] = dp[i][j-1] + 1;
    			for(int k = j - 1; k >= i; k --) {
    				if(c[k] == c[j]) dp[i][j] = min(dp[i][j], dp[i][k-1] + dp[k][j-1]);
    			}
    		}
    	}
    	
    	printf("Case %d: %d\n", ++ cas, dp[0][n - 1]);
    }
    
    return 0;
}
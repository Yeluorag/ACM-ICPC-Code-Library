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
const int inf = 0x3f3f3f3f, N = 20, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int base, k, num[N];
LL dp[1 << 17][20];
char str[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(base, k);
    	scanf("%s", str);
    	for(int i = 0; i < base; i ++ ) {
    		if(str[i] <= 'F' && str[i] >= 'A') num[i] = str[i] - 'A' + 10;
    		else num[i] = str[i] - '0'; 
    	}
    	mem(dp, 0);
    	n = strlen(str);
    	int all = (1 << n) - 1;	
    	dp[0][0] = 1;

    	for(int i = 1; i <= all; i ++) {
    		for(int j = 0; j < n; j ++) {
    			if(i & (1 << j)) {
    				int s = i - (1 << j);
    				for(int mod = 0; mod < k; mod ++) {
    					int nmod = (mod * base + num[j]) % k;
    					dp[i][nmod] += dp[s][mod];
    				}
    			}
    		}
    	}
    	printf("Case %d: %lld\n", ++ cas, dp[all][0]);
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 2e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N * 6], a[7], tot;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(1) {
    	tot = 0;
    	for(int i = 1; i <= 6; i ++) si(a[i]);
    	for(int i = 1; i <= 6; i ++) tot += i * a[i];
    	if(!tot) break;
    	printf("Collection #%d:\n", ++ cas);
    	if(tot & 1) {
    		puts("Can't be divided.\n");
    		continue;
    	} else {
    		int weight = tot / 2;
    		mem(dp, 0);
    		for(int i = 1; i <= 6; i ++) {
    			int tmp = a[i];
    			for(int k = 1; k < tmp; ) {
    				for(int j = weight; j >= k * i; j --) dp[j] = max(dp[j], dp[j - k * i] + k * i);
    				tmp -= k;
    				k <<= 1;
    			}
    			for(int j = weight; j >= tmp * i; j --) dp[j] = max(dp[j], dp[j - tmp * i] + tmp * i);
    		}
    		if(dp[weight] == weight) puts("Can be divided.\n");
    		else puts("Can't be divided.\n");
    	}
    }
    
    return 0;
}
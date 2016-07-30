/*
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
const int inf = 0x3f3f3f3f, N =  20 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
double p[N], none, dp[1 << 20];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	none = 0.0;
    	for(int i = 0; i < n; i ++) { scanf("%lf", &p[i]); none += p[i]; }
    	none = 1.0 - none;
    	int Lim = (1 << n) - 1;
    	dp[0] = 0.0;
    	for(int s = 1; s <= Lim; s ++) {
    		double sump = 0.0, sume = 1.0;
    		for(int i = 0; i < n; i ++) {
    			if((1 << i) & s) {
    				int newState = s ^ (1 << i);
    				sume += dp[newState] * p[i];
    				sump += p[i];
    			} 
    		}
    		dp[s] = sume / sump;
    	}
    	printf("%.5f\n", dp[Lim]);
    }
    
    return 0;
}
*/
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
double p[N], none;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	double ret = 0.0;
    	for(int i = 0; i < n; i ++) scanf("%lf", &p[i]);
    	int Lim = (1 << n) - 1;
	    for(int s = 1; s <= Lim; s ++) {
	    	int cnt = 0;
	    	double sum = 0.0;
	    	for(int i = 0; i < n; i ++) {
	    		if((1 << i) & s) {
	    			cnt ++;
	    			sum += p[i];
	    		}
	    	}
	    	if(cnt & 1) ret += 1. / sum;
	    	else ret -= 1. / sum;
	    }
	    printf("%.5f\n", ret);
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int c[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	mem(c, 0);
    	int x, y;
    	for(int i = 0; i < n; i ++) { 
    		sii(x, y);
    		c[i] = x - y;
    	}
    	int ans = 0, cnt = 0, sum = 0;
    	for(int i = 0; i < 2 * n; i ++) {
    		if(ans == n) break;
    		sum += c[i % n];
    		if(sum >= 0) cnt ++, ans = max(ans, cnt);
    		else sum = cnt = 0;
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}
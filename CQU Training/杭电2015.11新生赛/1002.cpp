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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, a, b, c;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%d%d%d%d",&n, &a, &b, &c) != EOF) {
    	int now = 0, x, ans = 0;
    	for(int i = 1; i <= n; i ++) {
    		si(x);
    		now += x;
    		if(now >= a && now < b) now = 0, ans += 2;
    		else if(now >= b && now < c) now = 0, ans += 3;
    		else if(now >= c) now = 0, ans += 4;
    	}
    	printf("%d\n", ans);

    }
    
    return 0;
}
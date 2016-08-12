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
int a[N], vis[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	for(int i = 1; i <= n; i ++) si(a[i]);
    	mem(vis, 0);
    	int ans = 1;
    	for(int i = 1; i <= n; i ++) {
    		int j = i, cnt = 0;
    		while(1) {
    			vis[j] = 1, cnt ++;
    			j = a[j];
    			if(vis[j]) break;
    		} if(!cnt) cnt = 1;
    		ans = ans * cnt / __gcd(ans, cnt);
    	}
    	printf("%d\n", ans);
    }

    
    return 0;
}
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
int a[N], h[N];
char maz[N][N];
bool cmp(int a, int b) { return a > b; }

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) != EOF) {
    	mem(h, 0);
    	for(int i = 0; i < n; i ++) scanf("%s", maz[i]);
    	int ans = 0;
    	for(int i = 0; i < n; i ++) {
    		for(int j = 0; j < m; j ++) {
    			if(maz[i][j] == '1') a[j] ++;
    			else a[j] = 0;
    		}
    		memcpy(h, a, sizeof(a));
    		sort(h, h + m, cmp);
    		for(int j = 0; j < m; j ++) ans = max(ans, h[j] * (j + 1));
    	}
    	printf("%d\n", ans);
    }
    
    return 0;
}
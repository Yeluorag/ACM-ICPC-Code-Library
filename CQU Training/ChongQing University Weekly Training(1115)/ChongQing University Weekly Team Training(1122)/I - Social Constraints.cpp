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
int a[25], wh[25], seat[25];
int u[25], v[25], c[25];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(sii(n, m) == 2 && (n || m)) {
        for(int i = 1; i <= m; ++i) siii(u[i], v[i], c[i]);
        int ans = 0;
        for(int i = 0; i < n; ++i) a[i] = i;
        do {
            for(int i = 0; i < n; ++i) wh[a[i]] = i;
            int ok = true;
            for(int i = 1; i <= m; ++i) {
                int dif = abs(wh[u[i]] - wh[v[i]]);
                if(c[i] > 0) {
                    if(dif > c[i]) {
                        ok = false;
                        break;
                    }
                } else {
                    if(dif < -c[i]) {
                        ok = false;
                        break;
                    }
                }
            }
            ans += ok;
        } while(next_permutation(a, a + n));
        printf("%d\n", ans);
    }
    
    return 0;
}
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
int a[N][N], l[N], r[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        sii(n, m);
        char c[2];
        mem(a, 0);
        getchar();
        for(int i = 1; i <= n; i ++) for(int j = 1; j <= m; j ++) {
            scanf("%s", c);
            if(c[0] == 'F') a[i][j] = a[i-1][j] + 1;
        }
        int ans = 0;
        for(int i = 1; i <= n; i ++) {
            for(int j = 1; j <= m; j ++) l[j] = r[j] = j;
            a[i][0] = a[i][m+1] = -1;
            for(int j = 2; j <= m; j ++) {
                int t = j;
                while(a[i][j] <= a[i][t - 1]) t = l[t-1];
                l[j] = t;
            }
            for(int j = m - 1; j > 0; j --) {
                int t = j;
                while(a[i][j] <= a[i][t + 1]) t = r[t+1];
                r[j] = t;
            }
            for(int j = 1; j <= m; j ++) {
                int t = (r[j] - l[j] + 1) * a[i][j];
                ans = max(ans, t);
            }
        }
        printf("%d\n", ans * 3);
    }
    return 0;
}
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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int b[N], h[N];
int st[N], top = 0;
int ans[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(n);
    FOR(i, 1, n) {
    	si(b[i]);
    }
    int pos = 0;  
    ans[0] = 0;  
    for(int i = 0; i <= n; i ++) {  
        if(b[i] > ans[pos]) ans[++ pos] = b[i];  
        else if(b[i] < ans[pos]) {  
            int mid = lower_bound(ans, ans + pos, b[i]) - ans;  
            ans[mid] = b[i];  
        }  
    }  
    int ans = n - pos;
    if(ans == n) ans --;
    printf("%d\n", ans);

    
    return 0;
}
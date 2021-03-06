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
const int inf = 0x3f3f3f3f, N = 10 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
struct point {
    int x, y;
} points[10];
char s[N][N];
int num[N], dp[N][300];
int tot, ans;

int Dis(int i, int j) {
    int d1 = abs(points[j].x - i);
    int d2 = abs(points[j].y - num[i]);
    int ret = 0;
    if(d1) ret ++; if(d2) ret ++;
    if(!abs(d1 - d2) && d1 && d2) ret --;
    return ret;
}

int make(int i, int j) {
    if(dp[i][j] != -1) return dp[i][j];
    int ret = inf;
    for(int k = 0; k < 8; k ++) 
        if(j & (1 << k)) 
            ret = min(ret, Dis(i - 1, k) + make(i - 1, j - (1 << k)));
    return dp[i][j] = ret;
}

void work() {
    mem(dp, -1), dp[0][0] = 0;
    ans = min(ans, make(8, 255));
}

void dfs(int k) {
    if(k == 8) {
        work();
        return;
    }
    for(int j = 0; j < 8; j ++) {
        num[k] = j;
        bool flag = true;
        for(int i = 0; i < k; i ++) {
            if((num[i] == num[k]) || (i + num[i] == k + num[k]) || (i - num[i] == k - num[k])) {
                flag = false;
                break;
            }
        }
        if(flag) dfs(k + 1);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
        tot = 0;
        ans = inf;
        for(int i = 0; i < 8; i ++) scanf("%s", s[i]);
        for(int i = 0; i < 8; i ++) for(int j = 0; j < 8; j ++) {
            if(s[i][j] == 'q') {
                points[tot].x = i,
                points[tot].y = j;
                tot ++;
            }
        }
        dfs(0);
        printf("Case %d: %d\n", ++ cas, ans);
    }
    
    return 0;
}

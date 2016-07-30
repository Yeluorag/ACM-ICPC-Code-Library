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
const int MAX = 1000000000;

int T, cas = 0;
int n, m;
int f[N], a[N], cnt[N], fa[N];
map<int, int> fab;
void init() {
    fab.clear();
    f[0] = 1, f[1] = 1; fab[1] = 1;
    for(int i = 2; i < N; i ++) {
        f[i] = f[i-1] + f[i-2];
        if(f[i] > MAX) {
            break;
        }
        if(!fab[f[i]]) fab[f[i]] = 1;
    }
}

int find(int x) {
    if(fa[x] != x) return fa[x] = find(fa[x]);
    return x;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //    freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    init();
    while(sii(n, m) != EOF) {
        mem(cnt, 0);
        int u, v, ans = -1;
        for(int i = 1; i <= n; i ++) {
            si(a[i]);
            fa[i] = i;
        }
        for(int i = 0; i < m; i ++) {
            sii(u, v);
            int x = find(u), y = find(v);
            fa[y] = x;
        }
        for(int i = 1; i <= n; i ++) {
            int x = find(i);
            if(fab[a[i]]) cnt[x] ++;
            ans = max(ans, cnt[x]);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
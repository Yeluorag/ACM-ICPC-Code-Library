#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int maxn = 10 + 5;

int n, m, cas = 1, maxd;
char maz[maxn][maxn];
int vis[4][2 * maxn], ans[maxn];

bool check() {
    for(int i = 0; i < n; i ++) {
        for(int j = 0; j < m; j ++) {
            if(maz[i][j] == 'X' && !vis[0][i] && !vis[1][j] && !vis[2][i+j] && !vis[3][n-i+j])
                return false;
        }
    }
    return true;
}
bool dfs(int d, int cur) {
    if(d == maxd) {
        return check();
    }else {
        for(int i = cur; i < n * m; i ++) {
            int nx = i / m, ny = i % m;
            int ta = vis[0][nx], tb = vis[1][ny], tc = vis[2][nx+ny], td = vis[3][n-nx+ny];
            vis[0][nx] = vis[1][ny] = vis[2][nx+ny] = vis[3][n-nx+ny] = 1;
            ans[d] = i;
            if(dfs(d + 1, i)) return true;
            vis[0][nx] = ta; vis[1][ny] = tb; vis[2][nx+ny] = tc; vis[3][n-nx+ny] = td;
        }
    }
    return false;
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    while(scanf("%d%d", &n, &m) == 2 && n && m) {
//        scanf("%d", &m);
        for(int i = 0; i < n; i ++) scanf("%s", maz[i]);
        for(maxd = 0; maxd <= 5; maxd ++) {
            mem(vis, 0);
            if(dfs(0, 0)) break;
        }
        printf("Case %d: %d\n", cas ++, maxd);
    }
    
    return 0;
}
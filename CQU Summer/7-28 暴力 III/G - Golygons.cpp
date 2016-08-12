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
const int maxn = 1 << 30;
const int dt = 200;

int T, n, k, res, fx[55], fy[55], vis[505][505], ans[25];
char dir[4] = { 'e', 'n', 's', 'w'};
int dx[4] = { 1, 0, 0, -1 };
int dy[4] = { 0, 1, -1, 0 };


bool check(int x, int y, int nx, int ny) {
    if(vis[nx+dt][ny+dt]) return true;
    
    for(int i = 0; i < k; i++) {
        if(x == nx && fx[i] == x) {
            if(fy[i] <= max(y, ny) && fy[i] >= min(y, ny)) return true;
        } else if(y == ny && fy[i] == y) {
            if(fx[i] <= max(x, nx) && fx[i] >= min(x, nx)) return true;
        }
    }
    return false;
}

void dfs(int x, int y, int cnt, int ld) {
    if(cnt == n) {
        if(x == 0 && y == 0) {
            res ++;
            for(int i = 0; i < cnt; i++)
                printf("%c", dir[ans[i]]);
            puts("");
        }
        return;
    }
    for(int i = 0; i < 4; i++) {
        if(i + ld == 3 || i == ld) continue;
        int nx = x + dx[i] * (cnt + 1), ny = y + dy[i] * (cnt + 1);
        if(check(x, y, nx, ny)) continue;
        ans[cnt] = i;
        vis[nx+dt][ny+dt] = 1;
        dfs(nx, ny, cnt + 1, i);
        vis[nx+dt][ny+dt] = 0;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        mem(fx, 0x3f);
        mem(fy, 0x3f);
        mem(vis, 0);
        res = 0;
        scanf("%d%d", &n, &k);
        for(int i = 0; i < k; i++) {
            scanf("%d%d", &fx[i], &fy[i]);
        }
        dfs(0, 0, 0, 4);
        printf("Found %d golygon(s).\n", res);
        puts("");
    }   
    return 0;
}
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
const int maxn = 1005;

int n, maxd, num, v[maxn], ans[maxn];

bool dfs(int d, int now) {
    if(d >= maxd)
        return now == n;

    for (int i = num - 1; i >= 0; i--) {
        int mx = 0;
        for (int j = 0; j < num; j++)
            mx = max(mx, v[j]);
        if ((now + mx) << (maxd - d - 1) < n) return false;
        v[num++] = now + v[i];
        if (dfs(d + 1, now + v[i])) return true;
        num--;
        v[num++] = now - v[i];
        if (dfs(d + 1,now - v[i])) return true;
        num--;
    }
    return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    memset(ans, -1, sizeof(ans));
    ans[1] = 0;
    while(scanf("%d", &n), n) {
        if (ans[n] == -1){
            maxd = 0;
            int t = 1;
            while(t < n) { t <<= 1; maxd ++; }
            while(1){
                memset(v, 0, sizeof(v));
                v[0] = num = 1;
                if(dfs(0, 1)) { ans[n] = maxd; break; }
                maxd ++;
            }
        }
        printf("%d\n", ans[n]);
    }
    return 0;
}
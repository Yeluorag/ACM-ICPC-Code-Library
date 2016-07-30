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
const int maxn = 1000 + 5;

int n, res, ans, Min, Max, Num;
int stick[maxn], vis[maxn];
bool cmp (int a, int b) { return a > b; }

bool dfs(int sum, int cnt, int idx) {
    if (sum > res) return false;
    if (cnt == Num) return true;
    int pre = -1;
    for (int i = idx; i < n; i ++) {
        if (!vis[i] && stick[i] != pre) {
            pre = stick[i];
            if (sum + stick[i] < res) {
                vis[i] = 1;
                if (dfs(sum + stick[i], cnt, i + 1)) return true;
                vis[i] = 0;
                if(sum == 0) return false;
            } else if (sum + stick[i] == res) {
                vis[i] = 1;
                if (dfs(0, cnt + 1, 0)) return true;
                vis[i] = 0;
                return false;
            }
        }
    }
    return false;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    while(scanf("%d", &n), n) {
        ans = inf; Max = 0;
        for (int i = 0; i < n; i ++) {
            scanf("%d", &stick[i]);
            Max += stick[i];
        }
        sort(stick, stick + n, cmp);
        Min = stick[0];
        for (res = Min; res <= Max; res ++) {
            mem(vis, 0);
            if(Max % res == 0) {
                Num = Max / res;
                if(dfs(0, 0, 0)) break;
            }
        }
        printf("%d\n", res);
    }
    
    return 0;
}
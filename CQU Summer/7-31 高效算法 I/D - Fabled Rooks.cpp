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
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
const int inf = 1 << 30;
const int N = 5000 + 5;

int n, ans[N][2];

struct node{
    int l, r, id;
    friend bool operator < (const node &a, const node &b) {
        if(a.l == b.l) return a.r > b.r;
        return a.l > b.l;
    }
};

bool solve(node *ar, int idx) {
    priority_queue<node> que;
    rep(i, n) que.push(ar[i]);
    int maxx = 0;
    while(!que.empty()) {
        node tmp = que.top(); que.pop();
        if(tmp.r < maxx) return false;
        if(tmp.l < maxx) {
            tmp.l = maxx;
            que.push(tmp);
            continue;
        }
        int cur = max(tmp.l, maxx);
        ans[tmp.id][idx] = cur;
        maxx = cur + 1;
    }
    return true;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    while(scanf("%d", &n), n) {
        node ar1[N], ar2[N];
        rep(i, n) {
            scanf("%d%d%d%d", &ar1[i].l, &ar2[i].l, &ar1[i].r, &ar2[i].r);
            ar1[i].id = ar2[i].id = i;
        }
        if(solve(ar1, 0) && solve(ar2, 1)) rep(i, n) printf("%d %d\n", ans[i][0], ans[i][1]);
        else puts("IMPOSSIBLE");
    }
    
    return 0;
}
#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <cmath>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30;
const int N = 1e5 + 5;

int L, D, n, ans;
struct node{
    double l, r;
    bool operator< (const node &rhs) const { return r < rhs.r; }
}a[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(scanf("%d%d", &L, &D) == 2) {
        ans = 0;
        double tmp = -1e20;
        scanf("%d", &n);
        rep(i, n) {
            int x, y;
            scanf("%d%d", &x, &y);
            double t = sqrt(D * D - y * y);
            a[i].l = x - t;
            a[i].r = x + t;
        }sort(a, a + n);
        rep(i, n) {
            if(tmp >= a[i].l && tmp <= a[i].r) continue;
            if(tmp < a[i].l) { ans ++; tmp = a[i].r; }
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
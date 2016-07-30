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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 3e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, ans, t;
char maz[N][N];
struct node {
    int x, y, id;
}a[3], b[3];
// Imp
bool cmp(node p, node q) {
    return p.y > q.y;
}
void init() {
    rep(i, 3) a[i].x = b[i].x, a[i].y = b[i].y, a[i].id = b[i].id;
}

bool work() {
    sort(a, a + 3, cmp);
    if(a[0].y == a[1].y && a[0].y == a[2].y) {
        if(a[0].x + a[1].x + a[2].x == t) {
            if(a[0].y == t){
                rep(i, a[0].x) rep(j, a[0].y) maz[i][j] = a[0].id + 'A';
                REP(i, a[0].x, a[0].x + a[1].x) rep(j, a[1].y) maz[i][j] = a[1].id + 'A';
                REP(i, a[0].x + a[1].x, t) rep(j, a[2].y) maz[i][j] = a[2].id + 'A';
                return true;
            }
            
        }
    }
    if(a[0].y == a[1].y + a[2].y) {
        if(a[1].x == a[2].x && a[1].x + a[0].x == t) {
            if(a[0].y == t) {
                rep(i, a[0].x) rep(j, a[0].y) maz[i][j] = a[0].id + 'A';
                REP(j, 0, a[1].y) REP(i, a[0].x, t) maz[i][j] = a[1].id + 'A';
                REP(j, a[1].y, t) REP(i, a[0].x, t) maz[i][j] = a[2].id + 'A';
                return true;
            }
        }
    }
    return false;
}

void sp(int i) { swap(a[i].x, a[i].y); }
void solve() {
    init(); if(work()) { n = t; return; }
    init(); sp(0); if(work()) { n = t; return; }
    init(); sp(1); if(work()) { n = t; return; }
    init(); sp(2); if(work()) { n = t; return; }
    init(); sp(0); sp(1); if(work()) { n = t; return; }
    init(); sp(0); sp(2); if(work()) { n = t; return; }
    init(); sp(2); sp(1); if(work()) { n = t; return; }
    init(); sp(0); sp(1); sp(2); if(work()) { n = t; return; }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    sii(b[0].x, b[0].y);
    sii(b[1].x, b[1].y);
    sii(b[2].x, b[2].y);
    rep(i, 3) b[i].id = i;
    init();
    n = -1;
    m = a[0].x * a[0].y + a[1].x * a[1].y + a[2].x * a[2].y;
    t = (int)sqrt(m);
    if(t * t == m) {
        solve();
    }
    printf("%d\n", n);
    if(n != -1) {
        rep(i, n) printf("%s\n", maz[i]);
    }
    return 0;
}
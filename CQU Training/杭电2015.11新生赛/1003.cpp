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
const double p = 1.0 / 6.0;
int T, cas = 0;
int n, m;
int a[3], b[3];
int x, y;
double ans;
bool cmp(int p, int q) { return p > q; }
void judge() {
    sort(b, b + 3, cmp);
    if(b[0] == b[1] && b[1] == b[2]) y = 3;
    else if(b[0] == b[1] || b[1] == b[2]) y = 2;
    else y = 1;
    
    sort(a, a + 3, cmp);
    if(a[0] == a[1] && a[1] == a[2]) x = 3;
    else if(a[0] == a[1] || a[1] == a[2]) x = 2;
    else x = 1;
}

void work() {
    ans = 0.0;
    judge();
    if(y == 3) {    // 1
        if(x == 3) {
            if(a[0] > b[0]) ans = 1.0;
            return;
        } else if(x == 2) {
            if(a[1] > b[0]) ans = p;
            return;
        } else return;
    }
    
    if(y == 2) {    //
        if(b[0] != b[1]) swap(b[0], b[2]);
        if(x == 3) { ans = 1.0; return; }
        else if(x == 2) {
            if(a[0] != a[1]) swap(a[0], a[2]);
            if(a[1] > b[1]) { ans = 1.0; return; }
            if(a[1] == b[1]) {
                if(a[2] > b[2]) { ans = 1.0; return; }
                else {
                    ans = (6 - b[2]) * p;
                    if(a[1] <= b[2]) ans += p;
                    return;
                }
            } else if(a[1] < b[1]) {
                ans = p; return;
            }
        } else {
            if(a[0] > b[1]) {
                ans = p;
                if(a[1] > b[1]) ans += p;
                else if(a[1] == b[1]) {
                    if(a[0] > b[2]) ans += p;
                }
                return;
            }
            else if(a[0] == b[1]) {
                if(a[1] <= b[2]) { ans = 0.0; return; }
                else { ans = p; return; }
            } else { ans = 0.0; return; }
        }
    }
    
    if(y == 1) {
        if(x == 2 || x == 3) { ans = 1.0; return; }
        else {
            if(a[0] > b[0]) { ans = 1.0; return; }
            else if(a[0] == b[0]) {
                if(a[1] > b[1]) { ans = 1.0; return; }
                else if(a[1] == b[1]) {
                    if(a[2] > b[2]) { ans = 1.0; return; }
                    else {
                        ans = (6 - b[2]) * p;
                        if(a[1] <= b[2]) ans += p;
                        if(a[0] <= b[2]) ans += p;
                        return;
                    }
                } else if(a[1] < b[1]) {
                    ans = (6 - b[1]) * p + p;
                    return;
                }
            } else if(a[0] < b[0]) {
                ans = (8 - b[0]) * p;
                return;
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        for(int i = 0; i < 3; i ++) si(a[i]);
        for(int i = 0; i < 3; i ++) si(b[i]);
        work();
        printf("%.3f\n", ans);
    }
    
    return 0;
}
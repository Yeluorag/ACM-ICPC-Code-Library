#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cassert>
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
const int N = 5e4 + 5;

int n, a, b, c, now;
int T, cas = 0;
VI ans;

void move(int dt) {
    printf("%d ", now);
    now += dt;
    if(abs(dt) == 1) if(a) a --;
    if(abs(dt) == 2) if(b) b --;
    if(abs(dt) == 3) if(c) c --;
}

void solve() {
    int rp = min(a, min(b, c));
    rep(i, rp / 2) { move(3); move(-2); move(1); move(3); move(-1); move(2); }
    rep(i, rp % 2) { move(3); move(-2); move(1); }
    if(!c) {
        while(a > 1) move(1);
        int k = b / 2, m = b % 2;
        if(m == 1) {
            FOR(i, 0, k) move(2);
            move(-1);
        } else {
            rep(i, k) move(2);
            move(1);
        }rep(i, k) move(-2);
    } else {
        
    }
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    cin >> T;
    while(T --) {
        ans.clear();
        scanf("%d%d%d", &a, &b, &c);
        n = a + b + c;
        now = 0;
        solve();
        
    }
    
    return 0;
}
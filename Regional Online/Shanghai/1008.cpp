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
#define ALL(v) v.begin(), v.endr()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, Q, M;
int a[N];
// Imp


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //    freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        sii(Q, M);
        int op, t;
        LL x = 1;
        printf("Case #%d:\n", ++ cas);
        FOR(i, 1, Q) {
            sii(op, t);
            a[i] = t;
            if(op == 1) {
                    x = x * (LL)a[i] % M;
            } else if(op == 2) {
                a[i] = a[t] = x = 1;
                FOR(j, 1, i) x = x * (LL)a[j] % M;
            }
            printf("%lld\n", x);
        }
    }
    
    return 0;
}
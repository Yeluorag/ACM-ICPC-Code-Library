// Header.
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cmath>
#include <cstdio>
#include <vector>
#include <string>
#include <sstream>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
LL a, b, t1, t2;
// Imp
LL judge(LL n) {
    if(n < 0) return -1;
    LL m = sqrt(n + 0.5);
    return m;
}
int main(){
    while(cin >> a >> b) {
        a --;
        LL p = judge(a), q = judge(b);
        if(p == -1) t1 = 0;
        else {
            if(p & 1) t1 = p * p - p * (p - 1) / 2;
            else t1 = a - p * (p + 1) / 2 + 1;
        }
        if(q & 1) t2 = q * q - q * (q - 1) / 2;
        else t2 = b - q * (q + 1) / 2 + 1;
        cout << t2 - t1 << endl;
    }
    return 0;
}
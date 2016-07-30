// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define TIME cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#define IN freopen("/Users/apple/input.txt", "r", stdin);
#define OUT freopen("/Users/apple/out.txt", "w", stdout);
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
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, b, idx;
int num[20];
// Imp

LL work(int rad) {
    LL ret = 0, t = 1;
    rep(i ,n) {
        ret += t;
        t *= rad;
    }
    return ret;
}

bool judge(LL t) {
    LL k = sqrt(t + 0.5);
    if(t == 1) return false;
    FOR(i, 2, k) if(t % i == 0) return false;
    return true;
}

bool solve(int rad) {
    LL num = work(rad);
    if(judge(num)) return true;
    return false;
}

int main(){
#ifdef LOCAL
    IN;
    //  OUT;
#endif
    
    while(sii(b, n) != EOF) {
        if(solve(b)) puts("YES");
        else puts("NO");
    }
    
    return 0;
}
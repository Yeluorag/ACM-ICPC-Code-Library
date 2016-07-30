// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <cctype>
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
#define repD(i, n) for(int i = (n); i; i --)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define REPD(i, t, n) for(int i = (n); i > (t); i --)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define FORD(i, t, n) for(int i = (n); i >= (t); i --)
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
int n, m;
char s1[N], s2[N];
// Imp
bool solve(int st, char s1[], char s2[]) {
    int n = strlen(s1), m = strlen(s2);
    rep(i, n) {
        int t = i + st >= m ? 0 : s2[i+st] - '0';
        if(s1[i] + t - '0' > 3) return false;
    }
    return true;
}

int main(){
#ifdef LOCAL
   IN // OUT
#endif
    
    while(ss(s1) != EOF) {
        ss(s2);
        int ans = inf;
        n = strlen(s1), m = strlen(s2);
        FOR(i, 0, m) if(solve(i, s1, s2)) {
            int tmp = max(i + n, m);
            Min(ans, tmp);
            break;
        }
        FOR(i, 0, n) if(solve(i, s2, s1)) {
            int tmp = max(i + m, n);
            Min(ans, tmp);
            break;
        }
        put(ans);
    }
    
    return 0;
}
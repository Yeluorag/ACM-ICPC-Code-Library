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
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e2 + 5, MOD = 1e9 + 7;
// Macro end

int T, cas = 0;
int n, m, dp[N][N];
char s[N];

// Imp
bool match(char a, char b) {
    if(a == '(' && b == ')') return true;
    if(a == '[' && b == ']') return true;
    return false;
}

void init() {
    rep(i, n) dp[i+1][i] = 0, dp[i][i] = 1;
    for(int i = n - 2; i >= 0; i --) {
        REP(j, i + 1, n) {
            dp[i][j] = n;
            if(match(s[i], s[j])) Min(dp[i][j], dp[i+1][j-1]);
            REP(k, i, j) Min(dp[i][j], dp[i][k] + dp[k + 1][j]);
        }
    }
}

void print(int i, int j) {
    if(i > j) return;
    if(i == j) {
//        printf("---%c---",s[i]);
        if(s[i] == '(' || s[i] ==')') printf("()");
        else printf("[]");
        return;
    }
    int tmp = dp[i][j];
    if(match(s[i], s[j]) && tmp == dp[i+1][j-1]) {
        putchar(s[i]);
        print(i + 1, j - 1);
        putchar(s[j]);
        return;
    }
    REP(k, i, j) {
        if(tmp == dp[i][k] + dp[k+1][j]) {
            print(i, k), print(k + 1, j);
            return;
        }
    }
}

void read() {
    getchar();
    gets(s);
    n = strlen(s);
}

// Main Pro
void solve() {
    read(), init();
    if(cas ++) ET;
    print(0, n - 1);
    ET;
    
}

//  #define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    
    si(T); getchar(); while(T --) solve();
    // while(~si(n), n) solve();
    // while(~sii(n, m), n + m) solve();
    
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
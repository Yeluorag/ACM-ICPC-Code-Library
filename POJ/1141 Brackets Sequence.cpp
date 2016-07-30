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
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int dp[N][N], f[N][N];
char s[N];
int check(int i, int j) {
    return (s[i] == '(' && s[j] == ')') || (s[i] == '[' && s[j] == ']');
}

void print(int i, int j) {
    if(i > j) return;
    if(f[i][j] == -1) {
        if(s[i] == '(' || s[i] == ')') printf("()");
        else printf("[]");
        print(i + 1, j);
    }
    if(f[i][j] > 0) {
        putchar(s[i]);
        print(i + 1, f[i][j] - 1);
        putchar(s[f[i][j]]);
        print(f[i][j] + 1, j);
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(gets(s)) {
        mem(dp, 0);
        mem(f, -1);
        n = strlen(s);
        for(int i = 0; i < n; i ++) dp[i][i] = 1;
        for(int j = 0; j < n; j ++) {
            for(int i = j - 1; i >= 0; i --) {
                dp[i][j] = dp[i+1][j] + 1;
                for(int k = i + 1; k <= j; k ++) {
                    if(check(i, k) && dp[i+1][k-1] + dp[k+1][j] < dp[i][j]) {
                        dp[i][j] = dp[i+1][k-1] + dp[k+1][j];
                        f[i][j] = k;
                    } 
                }
            }
        }
        
        print(0, n - 1);
        puts("");
    }
    
    return 0;
}
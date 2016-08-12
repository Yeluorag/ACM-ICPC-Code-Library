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

int T, cas = 0;
int n, k;
int f[N][N];
bool check(int i) {
    if(i == 0) return false;
    for(int j = 0; j < n; j ++)
        if(f[0][j] != f[i][j]) return false;
    return true;
}

void work(int i) {
    int b[N];
    for(int j = 0; j < n; j ++) b[j] = f[i-1][f[i-1][j] - 1];
    memcpy(f[i], b, sizeof(b));
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, k) != EOF) {
        for(int i = 0; i < n; i ++) si(f[0][i]);
        int mod;
        for(mod = 1; !check(mod - 1); mod ++) work(mod);
        mod --;
        if(mod) k = mod - k % mod;
        for(int i = 0; i < n; i ++) printf("%d\n", f[k][i]);
    }
    
    return 0;
}
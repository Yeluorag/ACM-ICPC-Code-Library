#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
typedef unsigned long long ull;
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
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
ull a, b, n;
int f[N][6 * N], g[N];

int Pow(ull a, ull b, int m) {
    if(b == 0) return 1;
    int k = Pow(a, b / 2, m);
    k = k * k % m;
    if(b % 2) k = k * a % m;
    return k;
}

void init() {
    REP(i, 2, N) {
        f[i][0] = 0;
        f[i][1] = 1;
        for(int j = 2; ; j ++) {
            f[i][j] = (f[i][j-1] + f[i][j-2]) % i;
            if(f[i][j-1] == 0 && f[i][j] ==1) {
                g[i] = j - 1;
                break;
            }
        }
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //  freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    init();
    while(T --) {
        cin >> a >> b >> n;
        if(a == 0 || n == 1) put(0);
        else {
            int k = Pow(a % g[n], b, g[n]);
            put(f[n][k]);
        }
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
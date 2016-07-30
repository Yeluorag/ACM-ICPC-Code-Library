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
const int inf = 0x3f3f3f3f, N = 1e6 + 5, MOD = 1e9 + 7;

int T, cas = 0;
bool vis[N];
LL p, k;
LL quick_mod(LL a, LL b, LL m) {
    LL ret = 1;
    a %= m;
    while(b > 0) {
        if(b & 1) ret = ret * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return ret;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    cin >> p >> k;
    if(k == 0) {
        cout << quick_mod(p, p - 1, MOD) << endl;
        return 0;
    } if(k == 1) {
        cout << quick_mod(p, p, MOD) << endl;
        return 0;
    }
    mem(vis, false);
    LL ans = 1; int cnt = 0;
    for(int i = 0; i < p; i ++) {
        int idx = i, flag = 0;
        while(!vis[idx]) {
            vis[idx] = 1; flag ++;
            idx = 1LL * idx * k % p;
        }
        cnt += flag > 1;
    }
    cout << quick_mod(p, cnt, MOD) << endl;
    return 0;
}
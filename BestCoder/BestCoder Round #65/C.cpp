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
const int inf = 0x3f3f3f3f, N = 5e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
int sum[N], a[N], b[N], bit[N];
int cal(int i) {
    int s = 0;
    while(i > 0) {
        s += bit[i];
        i -= i & -i;
    }
    return s;
}

void add(int i, int x) {
    while(i <= n) {
        bit[i] += x;
        i += i & -i;
    }
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    si(T);
    while(T --) {
        si(n);
        mem(bit, 0);
        sum[0] = a[0] = 0;
        for(int i = 1; i <= n; i ++) {
            si(sum[i]);
            a[i] = sum[i] - sum[i-1];
        }
        for(int i = n; i >= 1; i --) {
            int l = 0, r = n + 1, mid;
            while(l < r - 1) {
                mid = (l + r) >> 1;
                int cnt = cal(n + 1 - mid);
                int tmp = n - cnt - a[i];
                if(tmp < mid) r = mid;
                else l = mid;
            }
            b[i] = l;
            add(n + 1 - l, 1);
        }
        for(int i = 1; i < n; i ++) printf("%d ", b[i]);
        printf("%d\n", b[n]);
        
    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif
    
    return 0;
}
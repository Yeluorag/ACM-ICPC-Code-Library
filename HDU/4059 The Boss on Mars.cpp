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
const int inf = 0x3f3f3f3f, N = 1e3 + 5;
const LL MOD = 1e9 + 7;

int T, cas = 0;
int n, m, sz;
LL inv, ans;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
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

LL SumFour(LL n) {
    return n * (n + 1) % MOD * (2 * n + 1) % MOD *
    ((3 * n * n % MOD + 3 * n - 1) % MOD) % MOD * inv % MOD;
}
vector<int> primes;
void primes_init(int num) {
    primes.clear();
    int m = sqrt(num + 0.5);
    for(int i = 2; i <= m; i ++) {
        if(num % i == 0) {
            primes.pb(i);
            while(num % i == 0) num /= i;
        }
    } if(num > 1) primes.pb(num);
    sz = primes.size();
}

void Inclusion_Exclusion(int idx, LL lcm, LL cnt) {
    lcm = primes[idx] * lcm / gcd((LL)primes[idx], lcm);
    LL k = (LL)n / lcm, ret = 1;
    for(int i = 0; i < 4; i ++) ret = ret * lcm % MOD;
    ret = ret * SumFour(k) % MOD;
    if(cnt & 1) ans = (ans - ret + MOD) % MOD;
    else ans = (ans + ret) % MOD;
    for(int i = idx + 1; i < sz; i ++)
        Inclusion_Exclusion(i, lcm, cnt + 1);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    inv = quick_mod(30, MOD - 2, MOD);
    si(T);
    while(T --) {
        si(n);
        primes_init(n);
        if(sz == 0) {
            printf("0\n");
            continue;
        }
        ans = SumFour((LL)n);
        for(int i = 0; i < sz; i ++)
            Inclusion_Exclusion(i, 1, 1);
        
        printf("%lld\n", ans);
    }
    
    return 0;
}
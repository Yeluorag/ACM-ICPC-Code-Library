// Header.
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
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
const int inf = 0x3f3f3f3f, N = 5e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m, k, tot;
int prime[N], A[105], pcnt[5005][N];
int res[5005], cnt[N];
// Imp
int Euler_Phi(int n) {
    int ret = n;
    for(int i = 2; i * i <= n; i ++) if(n % i == 0) {
        ret = ret / i * (i - 1);
        while(n % i == 0) n /= i;
    } if(n > 1) ret = ret / n * (n - 1);
    return ret;
}

int cal(int num, int *t) {
    for(int i = 0; i < tot && prime[i] <= num; i ++) {
        if(num % prime[i] == 0) {
            int cnt = 0;
            while(num % prime[i] == 0) {
                num /= prime[i];
                cnt ++;
            }
            t[i] = cnt;
        }
    }
    return num;
}

void init(int num) {
    tot = 0;
    mem(cnt, 0);
    mem(prime, 0);
    mem(pcnt, 0);
    for(int i = 2; i * i <= num && i <= 5000; i ++) {
        if(num % i == 0) {
            while(num % i == 0) num /= i;
            prime[tot ++] = i;
        }
    }
    FOR(i, 1, 5000) res[i] = cal(i, pcnt[i]);
}

int quick_mod(int a, int b, int mod) {
    LL ret = 1;
    while(b) {
        if(b & 1) ret = ret * (LL)a % mod;
        a = (LL)a * (LL)a % mod;
        b /= 2;
    }
    return ret % mod;
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    while(sii(n, m) != EOF) {
        si(k);
        int sum = 0;
        rep(i, k) {
            si(A[i]);
            sum += A[i];
        }
        init(m);
        LL a = 1, b = 1;
        int t[N];
        for(int i = n * n - sum + 1; i <= n * n; i ++) {
            mem(t, 0);
            int tmp = cal(i, t);
            rep(i, tot) cnt[i] += t[i];
            a = a * tmp % m;
        }
        rep(i, k) {
            FOR(j, 2, A[i]) {
                rep(l, tot) cnt[l] -= pcnt[j][l];
                b = b * res[j] % m;
            }
        }
        LL ans = a;
        rep(i, tot) ans = ans * quick_mod(prime[i], cnt[i], m) % m;
        ans = ans * quick_mod(b, m - 2, m) % m;
        printf("%lld\n", ans);
    }
    
    return 0;
}
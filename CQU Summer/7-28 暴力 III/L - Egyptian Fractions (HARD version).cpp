#include <iostream>
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
typedef long long ll;
const int maxn = 100005;
ll now[maxn], ans[maxn], flag[10], a, b;
int maxd, k, T, cas = 1;

ll gcd(ll a, ll b) {
    return b == 0 ? a : gcd(b, a % b);
}

ll getNumber(ll a, ll b) {
    ll c = 1;
    for(; a * c < b; c++);
    return c;
}

bool isLegal(ll t) {
    for (int i = 0; i < k; i++) {
        if (flag[i] == t) {
            return false;
        }
    }
    return true;
}

bool check(int t) {
    for(int i = t; i >= 0; i--) {
        if(now[i] != ans[i])
            return ans[i] == -1 || now[i] < ans[i];
    }
    return false;
}

bool dfs(int d, ll st, ll a, ll b) {
    if(d == maxd) {
//        if(a == 0) return false;
        if(b % a) return false;
        now[d] = b / a;
        if(!isLegal(b / a)) return false;
        if(check(d)) memcpy(ans, now, sizeof(ll) * (d + 1));
        return true;
    }
    
    int res = 0;
    st = max(st, getNumber(a, b));
    for(ll i = st; ; i++) {
        if(b * (maxd + 1 - d) <= a * i) break;
        if(!isLegal(i)) continue;
        now[d] = i;
        ll nb = b * i;
        ll na = a * i - b;
        ll t = gcd(a, b);
        if(dfs(d + 1, i + 1, na / t, nb / t)) res = 1;
    }
    return res;
}

int main(){
//    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
    cin >> T;
    while(T --) {
        memset(flag, 0, sizeof(flag));
        scanf("%lld%lld%d", &a, &b, &k);
        for(int i = 0; i < k; i++){
            scanf("%lld", &flag[i]);
        }
        
        for(maxd = 1; ; maxd ++) {
            memset(ans, -1, sizeof(ans));
            if(dfs(0, getNumber(a, b), a, b)) break;
        }
        printf("Case %d: %lld/%lld=", cas++, a, b);
        for(int i = 0; i < maxd; i++)
            printf("1/%lld+", ans[i]);
        printf("1/%lld\n", ans[maxd]);
    }
    return 0;
}
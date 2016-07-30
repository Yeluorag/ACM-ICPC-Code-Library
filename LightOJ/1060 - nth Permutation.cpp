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

typedef unsigned long long ull;
#define mem(a, n) memset(a, n, sizeof(a))
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 20 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, cn;
char s[N],s2[N], to[N];
ull dp[N], f[N], k;
int cnt[N], cnt2[N], go[256];

ull get() {
	int sum = 0;
	for(int i = 0; i <= cn; i ++) sum += cnt[i];
	ull ans = f[sum];
	for(int i = 0; i <= cn; i ++) ans /= f[cnt[i]];
    return ans;
}

#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    f[0] = 1;
    for(int i = 1; i <= 20; i ++) f[i] = f[i-1] * i;
    si(T);
    while(T --) {
    	scanf("%s%llu", s, &k);
    	n = strlen(s);
    	sort(s, s + n);
        strcpy(s2, s);
        sort(s2, s2 + n);
        cn = 0;
        to[0] = s2[0];
        mem(cnt, 0);
        go[s2[0]] = 0;
        for(int i = 0; i < n; i ++) {
            if(i == 0 || s2[i-1] == s2[i]) {
                cnt[cn] ++;
            } else {
                cnt[++cn] ++;
                go[s2[i]] = cn;
                to[cn] = s2[i];
            }
        }
        printf("Case %d: ", ++ cas);
        if(k > get()) {
            puts("Impossible");
            continue;
        }
        ull sum = 0;
        for(int i = 0; i < n; i ++) {
            for(int j = 0; j <= cn; j ++) {
                if(cnt[j] == 0) continue;
                cnt[j] --;
                ull tmp = get();
                if(sum + tmp >= k) {
                    putchar(to[j]);
                    break;
                }
                cnt[j] ++;
                sum += tmp;
            }
        } puts("");
    } 
    return 0;
}

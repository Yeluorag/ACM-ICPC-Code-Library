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
typedef map<int, int>::value_type miit;
int T, cas = 0;
int n, m, num;
int b[N * N];
map<int, int> cnt;
// Imp
vector<int> ans;

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    ans.clear();
    si(n); m = n * n;
    num = 0;
    rep(i, m) {
        si(b[i]);
        cnt[b[i]] ++;
    }
    map<int, int>::reverse_iterator ite;
    
    for(ite = cnt.rbegin(); ite != cnt.rend(); ite ++) {
        int &s = ite->second, f = ite->first;
        while(s) {
            s --;
            rep(i, ans.size()) {
                int g = __gcd(f, ans[i]);
                cnt[g] -= 2;
            }
            ans.pb(f);
        }
    }

    int sz = ans.size();
    rep(i, sz - 1) printf("%d ", ans[i]);
    printf("%d\n", ans[sz - 1]);
    return 0;
}
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
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30, N = 1e2 + 5, MOD = 1e9 + 7;

int n, ans, now, r[N], flag[1000005];
char c[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    ans = 0;
    now = 0;
    mem(flag, 0);
    cin >> n;
    rep(i, n) {
        getchar();
        scanf("%c %d", &c[i], &r[i]);
    }
    rep(i, n) {
        int t = r[i];
        if(c[i] == '+') {
            flag[t] = 1;
            if(now == 0) ans ++;
            if(now > 0) now --;
        } else {
            if(!flag[t]) ans ++;
            now ++;
        }
    }
    printf("%d\n", ans);
    return 0;
}
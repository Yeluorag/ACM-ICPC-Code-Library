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
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 1000000 + 5;

int T, cas = 0;
int n, m, k, x[N], flag[1005];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
    //	freopen("/Users/apple/out.txt", "w", stdout);
#endif
    
    cin >> T;
    while(T --) {
        mem(flag, -1);
        int cnt = 0, l = 1, ans = inf;
        scanf("%d%d%d", &n, &m, &k);
        x[1] = 1;x[2] = 2;x[3] = 3;
        REP(i, 4, n + 1) x[i] = (x[i-1] + x[i-2] + x[i-3]) % m + 1;
        REP(i, 1, n + 1) {
            flag[x[i]] ++;
            if(x[i] <= k && !flag[x[i]]) cnt ++;
            while(flag[x[l]] > 0 || x[l] > k){
                flag[x[l]] --;
                l ++;
            }
           
            if(cnt == k) ans = min(ans, i - l + 1);
        }
        printf("Case %d: ", ++ cas);
        if(ans != inf) printf("%d\n", ans);
        else puts("sequence nai");
    }
    
    return 0;
}
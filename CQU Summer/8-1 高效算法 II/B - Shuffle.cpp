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
const int inf = 1 << 30;
const int N = 100000 + 5;

int T, cas = 0;
int s, n, a[3 * N], cnt[N], win[2 * N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        scanf("%d%d", &s, &n);
        mem(a, -1);
        mem(cnt, 0);
        mem(win, 0);
        rep(i, n) scanf("%d", &a[i+s]);
        int tot = 0;
        rep(i, n + s + 1) {
            if(tot == s || (i < s && tot == i) || (i > n && tot == n + s - i)) win[i] = 1;
            if(i == n + s) break;
            if(a[i] != -1 && cnt[a[i]] == 1)
                tot --;
            cnt[a[i]] --;
            if(a[i+s] != -1 && cnt[a[i+s]] == 0)
                tot ++;
            cnt[a[i+s]] ++;
            
        }
        int ans = 0;
        rep(i, s) {
            int ok = 1;
            for(int j = i; j < n + s + 1; j += s)
                if(!win[j]) { ok = 0; break; }
            if(ok) ans ++;
        }
        printf("%d\n",ans == n + 1 ? s : ans);
    }
    
    return 0;
}
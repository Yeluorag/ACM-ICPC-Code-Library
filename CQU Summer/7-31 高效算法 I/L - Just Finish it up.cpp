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
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 100000 + 5;

int T, n, cas = 0, p[N], q[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &p[i]);
        for(int i = 1; i <= n; ++i)
            scanf("%d", &q[i]);;
        int flag = 0, ans;
        for(ans = 1; ans <= n; ans ++){
            int i = ans, cur = p[i] - q[i], cnt = 0;
            while(cur >= 0) {
                if(++ i > n) i = 1;
                if(++ cnt > n) break;
                cur += p[i] - q[i];
            }
            if(cnt > n) {
                flag = 1;
                break;
            } else if (i < ans) break;
            else ans = i;
        }
        printf("Case %d: ", ++ cas);
        if(!flag) puts("Not possible");
        else printf("Possible from station %d\n", ans);
    }
    return 0;
}
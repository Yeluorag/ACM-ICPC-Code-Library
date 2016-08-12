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
const int N = 1000000 + 5;

int T, n, a[N];
map<int, int> mp;
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    
    cin >> T;
    while(T --) {
        scanf("%d", &n);
        for(int i = 1; i <= n; i ++) scanf("%d", &a[i]);
        int tmp = 0, ans = 0, l = 1;
        mp.clear();
        for(int i = 1; i <= n; i ++) {
            if(mp[a[i]] < l) {
                tmp ++;
                mp[a[i]] = i;
            } else {
                l = mp[a[i]] + 1;
                tmp = i - mp[a[i]];
                mp[a[i]] = i;
            }
            ans = max(ans, tmp);
        }
        printf("%d\n", ans);
    }
    
    return 0;
}
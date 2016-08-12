#define LOCAL
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
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 10000 + 5;

int n, ans, l, a[N], dp[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //    freopen("/Users/apple/out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);

    // mem(dp, 0);
    ans = 0;
    scanf("%d", &n);
    for(int i = 0; i < n; i ++) scanf("%d", &a[i]);
    for(int i = 0; i < n; i ++) {
        dp[a[i]] = 1;
        int t ;
        for(int j = l; j < i; j ++) {
            if(a[i] % a[j] == 0) dp[a[i]] = dp[a[j]] + 1;
        }
        ans = max(ans, dp[a[i]]);
    }
    
    printf("%d\n", ans);
    return 0;
}
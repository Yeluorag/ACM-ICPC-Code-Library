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
const int N = 10000 + 5;

int n;
LL a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
    std::ios::sync_with_stdio(false);
    
    while(scanf("%d", &n), n) {
        for(int i = 0; i < n; i ++) scanf("%lld", &a[i]);
        sort(a, a + n);
        LL ans = 0, temp = 0;
        for(int i = 0; i < n - 1; i ++) {
            temp = a[i] + a[i+1];
            ans += temp;
            int j = i + 2;
            for(; j < n; j ++) {
                if(a[j] < temp) a[j-1] = a[j];
                else break;
            }
            a[j - 1] = temp;
        }
        printf("%lld\n", ans);
    }
    
    return 0;
}
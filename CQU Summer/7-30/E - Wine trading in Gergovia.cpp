#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <cmath>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long ll;
#define mem(a,n) memset(a,n,sizeof(a))
const int inf = 1 << 30;
const int N = 100000 + 5;

int n;
ll a[N], sum[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif
	std::ios::sync_with_stdio(false);

    while(scanf("%d", &n), n) {
    	for(int i = 1; i <= n; i ++) scanf("%lld", &a[i]);
    	sum[0] = 0;
    	ll ans = 0;
    	for(int i = 1; i <= n; i ++) {
    		ans += abs(sum[i-1]);
    		sum[i] = sum[i-1] + a[i];
    	}
    	printf("%lld\n", ans);
    }
    
    return 0;
}
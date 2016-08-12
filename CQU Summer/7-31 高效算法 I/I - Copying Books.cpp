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
#define rep(i,n) for(int i = 0; i < (n); i ++)
const int inf = 1 << 30;
const int N = 500 + 5;

int T, m, k, idx, ans[N];
LL a[N], sum[N];

bool check(int x) {
	LL tmp = 0;
	idx = 0;
	rep(i, m) {
		tmp += a[i];
		if(tmp > x) {
			tmp = a[i];
			ans[idx++] = i - 1;
		}
		if(idx == k - 1) return sum[m-1] - sum[ans[idx-1]] <= x; 
	}
	return false;
}

#define LOCAL
int main(){
#ifdef LOCAL    
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    cin >> T;
    while(T --) {
    	scanf("%d%d", &m, &k);
    	sum[0] = 0;
    	rep(i, m) {
    		scanf("%lld", &a[i]);
    		sum[i] = sum[i-1] + a[i];
    	}
    	int l = 0, r = sum[m-1];
    	while(l < r) {
    		int mid = (l + r) >> 1;
    		if(check(mid)) break;
    		if(idx == k - 1) l = mid;
    		else r = mid;
    	}
    	idx = 0;
    	rep(i, m) {
    		printf("%lld ", a[i]);
    		if(i == ans[idx]) { printf("/ "); idx ++; }
    	}
    }
    
    return 0;
}
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
#define eps 1e-8
const int inf = 0x3fffffff, N = 2e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k, l, r;
int a[N], sum[N];
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	sii(n, k);
    	sum[0] = a[0] = 0;
    	for(int i = 1; i <= n; i ++) {
    		si(a[i]);
    		sum[i] = sum[i-1] + a[i];
    	}
    	int ans = -inf, l = 0, r = 0;
    	for(int i = n + 1; i <= n + k; i ++) sum[i] = sum[i-1] + a[i%n];

    	deque<int> que;
    	que.clear();
    	for(int i = 1; i < n + k; i ++) {
    		while(!que.empty() && sum[i-1] < sum[que.back()]) que.pop_back();
    		while(!que.empty() && que.front() < i - k) que.pop_front();
    		que.push_back(i - 1);
    		
    		if(sum[i] - sum[que.front()] > ans) {
    			ans = sum[i] - sum[que.front()];
    			l = que.front() + 1, r = i;
    		}
    	}
    	if(r > n) r -= n;
    	printf("%d %d %d\n", ans, l, r);
    }
    
    return 0;
}
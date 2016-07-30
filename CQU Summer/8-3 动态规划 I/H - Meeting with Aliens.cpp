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
const int inf = 1 << 30;
const int N = 1e3 + 5;

int n, a[N];

int solve(int *a) {
	int cnt = 0, b[N];
	memcpy(b, a, n * sizeof(int));
	rep(i, n) {
		if(b[i] != i + 1) {
			cnt ++;
			REP(j, i + 1, n) if(b[j] == i + 1) {
				swap(b[i], b[j]);
				break;
			}
		}
	}
	return cnt;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(scanf("%d", &n), n){
    	int ans = inf;
    	FOR(i, 1, n) {
    		scanf("%d", &a[i]);
    		a[i+n] = a[i];
    	}
    	FOR(i, 1, n) ans = min(ans, solve(a + i));
    	reverse(a + 1, a + 2 * n + 1);
    	FOR(i, 1, n) ans = min(ans, solve(a + i));
    	printf("%d\n", ans);
    }
    
    return 0;
}
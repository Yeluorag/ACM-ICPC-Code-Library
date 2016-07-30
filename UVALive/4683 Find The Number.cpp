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
#define ALL(v) v.begin(), v.end()
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define pb push_back
#define eps 1e-8
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const LL INF = 1000000000000000LL;
int T, cas = 0;
int n, m;
LL k, ans = 0;
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
vector<int> num;
void Inclusion_Exclusion(int idx, int cnt, LL lcm, LL b) {
	lcm = (LL)num[idx] * lcm / gcd((LL)num[idx], lcm);
	if(lcm > INF) return;
	if(cnt & 1) ans += b / lcm * cnt;
	else ans -= b / lcm * cnt;
	for(int i = idx + 1; i < n; i ++)
		Inclusion_Exclusion(i, cnt + 1, lcm, b);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	si(T);
	while(T --) {
		int x;
		scanf("%d%lld", &n, &k);
		num.clear();
		for(int i = 0 ; i < n ; i ++) {
			si(x);
			num.pb(x);
		}
		LL l = 1, r = INF;
		while(l < r - 1) {
			LL mid = (l + r) >> 1;
			ans = 0;
			for(int i = 0; i < n; i ++)
				Inclusion_Exclusion(i, 1, 1, mid);
			if(ans < k) l = mid;
			else r = mid;
		}

		printf("%lld\n", r);
	}
    
    return 0;
}
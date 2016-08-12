// Header.
#include <algorithm>
#include <iostream>
#include <sstream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <string>
#include <bitset>
#include <queue>
#include <stack>
#include <cmath>
#include <ctime>
#include <set>
#include <map>
using namespace std;

// Macro
typedef long long LL;
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define pb push_back
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;
const LL INF = (1 << 63);
// Macro end

int T, cas = 0;
int n, m;
char in[N];
LL fst, sec;
// Imp


#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(ss(in) != EOF) {
    	scanf("%lld%lld", &fst, &sec);
    	if(fst == 9) { puts("A"); continue; }
    	if(sec == 9) { puts("B"); continue; }
    	LL t = 0;
    	LL a[N];
    	mem(a, 0);
    	int flag = 1, ans = 0, ia = 0, ib = 1;
    	int len = strlen(in);
    	rep(i, len) {
    		if(in[i] >= '0' && in[i] <= '9') {
    			t = t * 10 + in[i] - '0';
    		} else {
    			if(flag == 1) { a[ia++] = t; ia +=2; }
    			else { a[ib++] = -t; ib += 2; }
    			t = 0;
    			if(in[i] == '+') flag = 1;
    			else flag = -1;
    		}
    	}
    	LL sum = 0;
    	rep(i, N) {
    		sum += a[i];
    		if(sum >= INF || sum <= -INF) break;
    	}
    	if(sum == sec) ans = 1;
    	printf("%c\n", 'A' + ans);
    }
    
    return 0;
}
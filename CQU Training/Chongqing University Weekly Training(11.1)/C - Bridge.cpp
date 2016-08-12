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

int T, cas = 0;
int n, m;
int a[N];

int strategy(int time[], int cap) {
	if(cap == 1) return time[0];
	if(cap == 2) return time[1];
	if(cap == 3) return time[0] + time[1] + time[2];
	if(2 * time[1] < time[0] + time[cap - 2])
		return time[0] + 2 * time[1] + time[cap - 1] + strategy(time, cap - 2);
	else 
		return 2 * time[0] + time[cap - 2] + time[cap - 1] + strategy(time, cap - 2);
}

void bridge(int time[], int cap) {
	if(cap == 1) {
		printf("%d\n", time[0]);
		return;
	}
	if(cap == 2) {
		printf("%d %d\n", time[0], time[1]);
		return;
	}
	if(cap == 3) {
		printf("%d %d\n", time[0], time[1]);
		printf("%d\n", time[0]);
		printf("%d %d\n", time[0], time[2]);
		return;
	}
	if(2 * time[1] < time[0] + time[cap - 2]) {
		printf("%d %d\n", time[0], time[1]);
		printf("%d\n", time[0]);
		printf("%d %d\n", time[cap - 2], time[cap - 1]);
		printf("%d\n", time[1]);
	} else {
		printf("%d %d\n", time[0], time[cap - 1]);
		printf("%d\n", time[0]);
		printf("%d %d\n", time[0], time[cap - 2]);
		printf("%d\n", time[0]);
	}
	bridge(time, cap - 2);
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    si(T);
    while(T --) {
    	si(n);
    	for(int i = 0; i < n; i ++) si(a[i]);
    	sort(a, a + n);
    	printf("%d\n", strategy(a, n));
    	bridge(a, n);
    	if(T) puts("");
    }
    
    return 0;
}
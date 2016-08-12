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
const int inf = 0x3f3f3f3f, N = 1e4 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
bool vis[N];
int num[N], tot = 0;
void Init_Primes() {
	mem(vis, 0);
	int m = sqrt(N + 0.5);
	for(int i = 2; i <= m; i ++) if(!vis[i])
		for(int j = i * i; j < N; j += i) vis[j] = 1; 
	for(int i = 2; i < N; i ++) if(!vis[i]){
		num[tot++] = i * i;
	}
}


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    Init_Primes();
    si(T);
    while(T --) {
    	si(n);
    	int l = lower_bound(num, num + tot, n) - num;
    	if(l == 0) {
    		printf("%d\n", num[l]);
    		continue;
    	}
    	int r = l --;
    	if(abs(num[l] - n) < abs(num[r] - n)) printf("%d\n", num[l]);
    	else printf("%d\n", num[r]);
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 3e2 + 5, MOD = 1e9 + 7;
const int base = 1e4, M = 300;

int T, cas = 0;
int n, m;
int h[N][M], ans[M];
void mul(int i, int k) {
	int carry = 0;
	for(int j = 0; j < M; j ++) {
		h[i][j] = h[i-1][j] * (4 * i - 2);
		h[i][j] += carry;
		carry = h[i][j] / base;
		h[i][j] %= base;
	}
}

void divd(int i, int k) {
	int carry = 0;
	for(int j = M - 1; j >= 0; j --) {
		h[i][j] += carry * base;
		carry = h[i][j] % k;
		h[i][j] /= k;
	}
}

void print() {
	int t = M - 1;
	while(ans[t] == 0) t--;
	printf("%d", ans[t--]);
	for(int j = t; j >= 0; j --) printf("%04d", ans[j]);
	puts("");
}

void init() {
	mem(h, 0);
	h[1][0] = 1;
	for(int i = 2; i <= M; i ++) {
		mul(i, 4 * i - 2);
		divd(i, i + 1);
	}
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
	init();
    while(si(n), n) {
    	int carry;
    	memcpy(ans, h[n], sizeof(h[n]));
    	for(int i = 1; i <= n; i ++) {
    		carry = 0;
    		for(int j = 0; j < M; j ++) {
    			ans[j] *= i;
    			ans[j] += carry;
    			carry = ans[j] / base;
    			ans[j] %= base;
    		}
    	}
    	print();
    }
    
    return 0;
}
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
const int inf = 0x3f3f3f3f, N = 2e2 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, k;
char s[N];
bool vis[N];
struct node {
	int num, len;
} a[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n) != EOF) {
    	for(int i = 1; i <= n; i ++) si(a[i].num);
    	mem(vis, false);
    	for(int i = 1; i <= n; i ++) {
    		int cnt = 0, idx = i;
    		while(!vis[idx]) {
    			vis[idx] = 1;
    			cnt ++;
    			idx = a[idx].num;
    		}
    		idx = i;
    		for(int j = 0; j < cnt; j ++) {
    			a[idx].len = cnt;
    			idx = a[idx].num;
    		}
    	}
    	while(si(k), k) {
    		gets(s);
    		char ans[N];
    		int sz = strlen(s);
    		for(int i = sz; i <= n; i ++) s[i] = ' '; s[n+1] = '\0';
    		for(int i = 1; i <= n; i ++) {
    			int cnt = k % a[i].len, idx = i;
    			for(int i = 0; i < cnt; i ++) idx = a[idx].num;
    			ans[idx] = s[i];
    		} ans[n+1] = '\0';
    		puts(ans + 1);
    	}
    	puts("");
	}
    
    return 0;
}
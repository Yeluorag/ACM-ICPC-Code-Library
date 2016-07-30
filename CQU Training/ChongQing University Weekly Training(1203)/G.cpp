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
int n, m, top;
int df[N], bf[N], hs[N], st[N];
vector<int> son[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
     while(si(n) != EOF) {
     	top = 0;
        mem(hs, -1);
        for(int i = 0; i < n; i ++) {
        	si(bf[i]);
        	hs[bf[i]] = i;
        	son[bf[i]].clear();
        }
        for(int i = 0; i < n; i ++) si(df[i]);
        st[top ++] = df[0];
        for(int i = 1; i < n; i ++) {
        	while(top) {
        		int u = st[top - 1];
        		if(hs[u] < hs[df[i]] - 1 || u == bf[0]) {
        			st[top ++] = df[i];
        			son[u].pb(df[i]);
        			break;
        		} else top --;
        	}
        }
        for(int i = 1; i <= n; i ++) {
        	printf("%d:", i);
        	for(int j = 0; j < son[i].size(); j ++) 
        		printf(" %d", son[i][j]);
        	puts("");
        }
    }
    
    return 0;
}
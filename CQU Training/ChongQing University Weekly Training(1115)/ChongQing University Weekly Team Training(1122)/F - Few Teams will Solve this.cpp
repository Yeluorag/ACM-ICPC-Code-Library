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
int bf[N], df[N], hb[N], hd[N];
vector<int> son[N];
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	for(int i = 0; i < n; i ++) {
    		si(bf[i]);
    		hb[bf[i]] = i;
    		son[bf[i]].clear();
    	}
    	for(int i = 0; i < n; i ++) {
    		si(df[i]);
    		hd[df[i]] = i;
    	}
    	stack<int> st;
    	st.push(df[0]);
    	for(int i = 1; i < n; i ++) {
    		while(!st.empty()) {
    			int u = st.top();
    			
    		}
    	}
    }
    
    return 0;
}
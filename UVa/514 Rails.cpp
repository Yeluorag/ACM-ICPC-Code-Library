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
int train[N];


int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(si(n), n) {
    	while(si(train[1]), train[1]) {
	    	for(int i = 2; i <= n; i ++) si(train[i]);
	    	stack<int> s;
	    	bool ok = true;
	    	int cnt = 1, cur = 1;
	    	while(cnt <= n) {
	    		if(!s.empty() && s.top() == train[cnt]) {
	    			s.pop();
	    			cnt ++;
	    		} else if(cur != train[cnt]) { 
	    			s.push(cur ++);
	    			if(cur > n) break;
	    		} else { cnt ++, cur ++; }
	    	}

	    	printf("%s\n", cnt > n ? "Yes" : "No");
    	}
    	puts("");
    }
    
    return 0;
}
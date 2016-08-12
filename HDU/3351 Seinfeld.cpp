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
const int inf = 0x3f3f3f3f, N = 4e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%s", s) != EOF) {
    	if(s[0] == '-') break;
    	n = strlen(s);
    	char t[N];
    	int top = 0, ans = 0;
    	for(int i = 0; i < n; i ++) {
    		if(s[i] == '}') {
    			if(top && t[top - 1] == '{') top --;
    			else t[top ++] = s[i];
    		} else t[top ++] = s[i];
    	}

    	ans = top / 2;
    	for(int i = 1; i < top; i += 2) if(t[i-1] == '}' && t[i] == '{') ans ++;
    	
    	printf("%d. %d\n", ++ cas, ans);
    }
    
    return 0;
}
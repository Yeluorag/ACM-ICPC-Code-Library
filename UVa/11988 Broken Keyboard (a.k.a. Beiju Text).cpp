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
const int inf = 0x3f3f3f3f, N = 1e5 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, m;
char s[N];
int nxt[N];
#define LOCAL
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif
	
    while(scanf("%s", s + 1) != EOF) {
    	int len = strlen(s + 1);
        int cur = 0, last = 0;
        s[0] = '?';
        mem(nxt, 0);
        
        for(int i = 1; i <= len; i ++) {
			if(s[i] == '[') {
				cur = 0;
			} else if(s[i] == ']') {
				cur = last;
			} else {
				nxt[i] = nxt[cur];
				nxt[cur] = i;
				if(cur == last) last = i;
				cur = i;
			}
        }
        for(int i = nxt[0]; i != 0; i = nxt[i]) {
            printf("%c", s[i]);
        } puts("");

    }
    
    return 0;
}
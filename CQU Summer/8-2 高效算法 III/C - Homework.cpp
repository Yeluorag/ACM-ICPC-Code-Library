#include <iostream>
#include <sstream>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <stack>
#include <string>
#include <cstring>
#include <algorithm>
using namespace std;
typedef long long LL;
#define mem(a,n) memset(a,n,sizeof(a))
#define rep(i,n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = t; i < n; i ++)
#define ALL(v) v.begin(), v.end()
const int inf = 1 << 30;
const int N = 100000 + 5;

int n, k, ans = 0, cnt[30];
char s[N];

int find() {
	int res = inf, idx = -1;
	rep(i, 26) {
		if(cnt[i] && cnt[i] < res) {
			res = cnt[i];
			idx = i;
		}
	}
	return idx;
}
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    scanf("%s", s);
    cin >> k;
    n = strlen(s);
    mem(cnt, 0);
    rep(i, n) cnt[s[i]-'a'] ++;
    while(k) {
    	int t = find();
    	if(t == -1) break;
    	if(k >= cnt[t]) {
    		k -= cnt[t];
    		cnt[t] = 0;
    	} else {
    		cnt[t] -= k;
    		k = 0;
    	}
    }
    rep(i, 26) if(cnt[i]) ans ++;
    printf("%d\n", ans);
    rep(i, n) if(cnt[s[i]-'a']) printf("%c", s[i]);
    puts("");
    return 0;
}
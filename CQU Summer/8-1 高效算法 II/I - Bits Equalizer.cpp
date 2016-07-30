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
const int inf = 1 << 30;
const int N = 100 + 5;

int T, cas = 0;
int ol, lo, wh[2], ans;
char s[N], t[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt","r",stdin);
    //	freopen("/Users/apple/out.txt","w",stdout);
#endif

    cin >> T;
    while(T --) {
    	scanf("%s", s);
    	scanf("%s", t);
    	ans = 0; ol = 0; lo = 0;
    	mem(wh, 0);
    	int len = strlen(s);
    	rep(i, len) {
    		if(s[i] == '0' && t[i] == '1')  ol ++;
    		else if(s[i] == '1' && t[i] == '0') lo ++;
    		if(s[i] == '?') wh[t[i]-'0'] ++;
    	}
    	if(ol >= lo) {
    		ans = ol + wh[0] + wh[1];
    	} else {
    		if(wh[1] >= lo - ol) {
    			ans = lo  + wh[1]  + wh[0];
    		} else ans = -1;
    	} 
    	printf("Case %d: %d\n", ++ cas, ans);
    }
    
    return 0;
}
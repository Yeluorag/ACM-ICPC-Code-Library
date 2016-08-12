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
#define mem(a, n) memset(a, n, sizeof(a))
#define rep(i, n) for(int i = 0; i < (n); i ++)
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define Min(a, b) a = min(a, b)
#define Max(a, b) a = max(a, b)
#define put(a) printf("%d\n", a)
#define ss(a) scanf("%s", a)
#define si(a) scanf("%d", &a)
#define sii(a, b) scanf("%d%d", &a, &b)
#define siii(a, b, c) scanf("%d%d%d", &a, &b, &c)
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 0x3f3f3f3f, N = 1e3 + 5, MOD = 1e9 + 7;

int T, cas = 0;
int n, l, c, cnt, sum, t[N], vis[N][N], dp[N][N];

int cal(int x) {
	if(!x) return 0;
	if(x <= 10) return - c;
	else return (x - 10) * (x - 10);
}
int dfs(int x,int y)  {  
    int &flag = vis[x][y];  
    int &ret = dp[x][y];  
    if(flag) return ret;  
    else if(x==0) {  
        flag=1;  
        ret = (y == 0 ? 0 : inf);  
    } else {  
        ret = inf;  
        int temp = 0;  
        for(int i = y; i > 0; i --) {  
            temp += t[i];  
            if(temp > l) break;  
            int ans = dfs(x - 1, i - 1);  
            if(ans != inf) Min(ret, ans + cal(l - temp));  
        }  
        flag = 1;  
    }  
    return ret; 
}

int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//  freopen("/Users/apple/out.txt", "w", stdout);
#endif

    while(si(n) != EOF) {
    	if(!n) break;
    	if(cas ++) ET;
    	mem(dp, 0);
    	mem(vis, 0);
    	sii(l, c);
    	FOR(i, 1, n) si(t[i]);
    	cnt = 0; sum = 0;
    	FOR(i, 1, n) {
    		sum += t[i];
    		if(sum > l) { cnt ++, sum = t[i]; }
    	}
    	printf("Case %d:\n", cas);  
        printf("Minimum number of lectures: %d\n", ++ cnt);  
        printf("Total dissatisfaction index: %d\n", dfs(cnt, n));  

    }
    
#ifdef LOCAL
    cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s." << endl;
#endif

    return 0;
}
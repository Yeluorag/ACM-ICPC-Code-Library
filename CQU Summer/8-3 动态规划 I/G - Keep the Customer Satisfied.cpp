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
#define REP(i, t, n) for(int i = (t); i < (n); i ++)
#define FOR(i, t, n) for(int i = (t); i <= (n); i ++)
#define ALL(v) v.begin(), v.end()
#define VI vector<int>
#define PII pair<int, int>
#define pb push_back
#define ET puts("")
const int inf = 1 << 30;
const int N = 8e5 + 5;

int T, cas = 0;
int n;
struct node{
	int l, r;
	bool operator < (const node &rhs) const { return r < rhs.r; }
}a[N];
int main(){
#ifdef LOCAL
    freopen("/Users/apple/input.txt", "r", stdin);
//	freopen("/Users/apple/out.txt", "w", stdout);
#endif

    cin >> T;
    while(T --) {
    	if(cas ++) ET;
    	int ans = 0;
    	priority_queue<int> que;
    	scanf("%d", &n);
    	rep(i, n) scanf("%d%d", &a[i].l, &a[i].r);
    	sort(a, a + n);
    	int ul = 0;
    	rep(i, n) {
    		ul += a[i].l;
    		ans ++;
    		que.push(a[i].l);
    		if(ul > a[i].r) {
    			ul -= que.top();
    			que.pop();
    			ans --;
    		}
    	}
    	printf("%d\n", ans);
    }
    return 0;
}